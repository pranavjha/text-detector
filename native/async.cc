#include <iostream>
#include <node.h>
#include <nan.h>
#include "ocr/main.h"
#include "async.h"

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

class OcrWorker : public AsyncWorker {
    public:
        OcrWorker(Callback *callback, string path, bool detectRegions) : AsyncWorker(callback), path(path), detectRegions(detectRegions), decodedText("") {}

        ~OcrWorker() {}

        void Execute () {
            decodedText = Ocr(path, detectRegions);
        }

        void HandleOKCallback () {
            Local<Value> argv[] = {
                Null(),
                Nan::New(decodedText).ToLocalChecked()
            };
            callback->Call(2, argv);
        }

    private:
        string path;
        bool detectRegions;
        string decodedText;
};

// Asynchronous access to the `Ocr()` function
NAN_METHOD(GetTextAsync) {
    // get the value of path
    String::Utf8Value p(info[0]);
    string path = string(*p);
    // the second (optional) parameter is false if region detection has to be skipped
    bool detectRegions = true;
    // if the second argument is passed, we use it
    if (info.Length() > 2){
        detectRegions = To<bool>(info[1]).FromJust();
    }
    // callback will be the last argument
    Callback *callback = new Callback(info[info.Length() - 1].As<Function>());
    // call the Ocr here - Async
    AsyncQueueWorker(new OcrWorker(callback, path, detectRegions));
}
