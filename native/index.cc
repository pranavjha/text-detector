#include <nan.h>
#include "sync.h"
#include "async.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

// Expose synchronous and asynchronous access to Ocr
NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("getTextSync").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(GetTextSync)).ToLocalChecked());

  Set(target, New<String>("getText").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(GetTextAsync)).ToLocalChecked());
}

NODE_MODULE(textdetector, InitAll)
