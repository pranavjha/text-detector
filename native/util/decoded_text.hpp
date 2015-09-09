#ifndef TEXTDETECTOR_DECODEDTEXT
#define TEXTDETECTOR_DECODEDTEXT

#include <node.h>
#include <vector>
#include <string>
#include <nan.h>

#include "box.hpp"

struct DecodedText
{
  Box box;
  std::vector<std::string> words;
  std::vector<float> confs;
  v8::Local<v8::Object> object;

  v8::Local<v8::Object> ToLocal()
  {
    v8::Isolate* isolate = NULL;
    v8::Local<v8::Array> l_box = box.ToLocal();
    v8::Local<v8::Array> l_words = v8::Array::New(words.size());
    v8::Local<v8::Array> l_confs = v8::Array::New(confs.size());

    for(int i=0;i<words.size();i++){
      l_words->Set(i,Nan::New(words[i]).ToLocalChecked());
    }

    for(int i=0;i<confs.size();i++){
          l_confs->Set(i,v8::NumberObject::New(confs[i]));
        }
	v8::Local<v8::Object> out = v8::Object::New();
    out->Set(Nan::New("box").ToLocalChecked(), l_box);
	out->Set(Nan::New("words").ToLocalChecked(), l_words);
      out->Set(Nan::New("confidences").ToLocalChecked(), l_confs);
    return out;
  }
  
};
#endif
