#ifndef TEXTDETECTOR_BOX_HPP
#define TEXTDETECTOR_BOX_HPP

#include <node.h>

struct Box
{
  v8::Local<v8::Array> ToLocal()
  {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Array> array = v8::Array::New(4);
    array->Set(0,v8::Integer::New(1));
	array->Set(1,v8::Integer::New(2));
	array->Set(2,v8::Integer::New(3));
	array->Set(3,v8::Integer::New(4));
	return array;
  }

  int x1, x2, y1, y2;
};

#endif
