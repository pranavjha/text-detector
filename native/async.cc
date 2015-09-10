#include <iostream>
#include <node.h>
#include <nan.h>
#include "async.h"
#include <ocr/ocr.hpp>
#include <string>
#include <stdlib.h>
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
        OcrWorker(Callback *callback, string path,Box box) : AsyncWorker(callback), path(path), box(box), decodedText() {}

        ~OcrWorker() {}

        void Execute () {
		if(box.x1){
			 decodedText = Ocr(path, box);
		}
		else{
            		decodedText = Ocr(path);
		}
        }

        void HandleOKCallback () {
            Local<Value> argv[] = {
                Nan::Null(),
                decodedText.ToLocal()//Nan::New(decodedText).ToLocalChecked()
            };
            callback->Call(2, argv);
        }

    private:
        string path;
        Box box;
        OutputOcr  decodedText;
};

// Asynchronous access to the `Ocr()` function
NAN_METHOD(GetTextAsync) {
    // get the value of path
    String::Utf8Value p(info[0]);
    string path = string(*p);
    Box box;
    // the second (optional) parameter is false if region detection has to be skipped
    // if the second argument is passed, we use it
	if(info.Length() >2 ) {
 	   v8::Local<v8::Array> boxArr= v8::Local<v8::Array>::Cast(info[1]);
	   int arr[boxArr->Length()];
           for(int i =0;i< boxArr->Length();i++){
              String::Utf8Value xp(boxArr->Get(i)->ToString());
              string x=string(*xp);
              //convert to int
              int pos=atoi(x.c_str());
              arr[i]=pos;
           }
	   box = Box(arr);
	}
	// callback will be the last argument
   	 Callback *callback = new Callback(info[info.Length() - 1].As<Function>());
    	// call the Ocr here - Async
    	AsyncQueueWorker(new OcrWorker(callback, path, box));
}

