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
    v8::Local<v8::Object> out = v8::Object::New();
    out->Set(Nan::New("box").ToLocalChecked(), l_box);
    return out; 
  }
};

#endif
