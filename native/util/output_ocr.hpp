#ifndef TEXTDETECTOR_OUTPUTOCR
#define TEXTDETECTOR_OUTPUTOCR

#include <vector>
#include <vector>
#include <node.h>
#include <nan.h>

#include "box.hpp"
#include "decoded_text.hpp"

struct OutputOcr
{
  Box box;
  std::vector<DecodedText> text_vec;  

  v8::Local<v8::Object> ToLocal()
  { 
    v8::Local<v8::Array> l_box = box.ToLocal();
    v8::Local<v8::Array> l_decodedArr= v8::Array::New(text_vec.size());
    for(int i=0;i<text_vec.size();i++){
    	v8::Local<v8::Object> l_decodedtext = text_vec[i].ToLocal();
	l_decodedArr ->Set(i,l_decodedtext);
    }
    v8::Local<v8::Object> out = v8::Object::New();
    out->Set(Nan::New("box").ToLocalChecked(), l_box);
    out->Set(Nan::New("decodedText").ToLocalChecked(),l_decodedArr);
    return out; 
  }
};

#endif
