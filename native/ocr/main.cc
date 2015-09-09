#include "main.h"
#include <iostream>

using namespace std;
class Box{
public:
    int x1,x2,y1,y2;
};
class decodedTxtRegion{
public:
    Box box;
    vector<string> words;
    vector<float> confidences;
};
class outputOCR{
public:
    Box box;
    vector<decodedTxtRegion> decodedText;

};

string Ocr (string path, bool detectRegion) {
    outputOCR op;
    Box box;
    box.x1=1;
    box.x2=2;
    box.y1=3;
    box.y2=4;
    decodedTxtRegion dt,dt1;
    vector<string> words,cf;
    words.push_back("w1");
    word.push_back("w2");
    cf.push_back("c1");
    cf.push_back("c2");
    dt.box=box;
    dt.words=words;
    dt.confidences=cf;
    dt1.box=box;
    dt1.words=words;
    dt1.confidences=cf;

    vector<decodedTxtRegion> dtr;
    dtr.push_back(dt);
    dtr.push_back(dt1);
    op.box=box;
    op.decodedText=dtr;
    return op;
}

