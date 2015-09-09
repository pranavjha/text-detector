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

    v8::Local<v8::Object> out = v8::Object::New();
    out->Set(Nan::New("box").ToLocalChecked(), l_box);
    return out;
  }
  
};
#endif
