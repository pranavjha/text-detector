#ifndef TEXTDETECTOR_BOX_HPP
#define TEXTDETECTOR_BOX_HPP

#include <node.h>

struct Box
{
  v8::Local<v8::Array> ToLocal()
  {
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Array> array = v8::Array::New(4);
    array->Set(0,v8::Integer::New(x1));
	array->Set(1,v8::Integer::New(x2));
	array->Set(2,v8::Integer::New(y1));
	array->Set(3,v8::Integer::New(y2));
	return array;
  }
  Box() {
  	x1=x2=y1=y2=NULL;
  }
  Box(int b[]){
    x1=b[0];
    x2=b[1];
    y1=b[2];
    y2=b[3];
  }

  int x1, x2, y1, y2;
};

#endif
