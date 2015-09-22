#include <iostream>
#include <node.h>
#include <nan.h>
#include "sync.h"
#include <ocr/ocr.hpp>

using namespace std;
using namespace v8;
using namespace Nan;
using v8::Function;
using v8::Local;
using v8::Number;
using v8::Value;
using Nan::AsyncQueueWorker;
using Nan::AsyncWorker;
using Nan::Callback;
using Nan::HandleScope;
using Nan::New;
using Nan::Null;
using Nan::To;

// Simple synchronous access to the `GetText()` function
NAN_METHOD(GetTextSync) {
    // get the value of path
    String::Utf8Value p(info[0]);
    string path = string(*p);
    // the second (optional) parameter is false if region detection has to be skipped
    OutputOcr detectRegions;
    // if the second argument is passed, we use it
    if (info.Length() > 1){
        //detectRegions = To<bool>(info[1]).FromJust();
    }
    // call the decoder here
    OutputOcr decodedText = Ocr(path, Box());
    // set the return value
    info.GetReturnValue().Set(Nan::New(decodedText.ToLocal()));
}
