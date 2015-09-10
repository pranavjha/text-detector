#include <iostream>
#include <string>

#include <util/box.hpp>
#include <util/output_ocr.hpp>
#include <util/decoded_text.hpp>

using namespace std;

OutputOcr Ocr (string path, Box) {
    OutputOcr op;
    Box box;
    box.x1=1;
    box.x2=2;
    box.y1=3;
    box.y2=4;
    DecodedText dt,dt1;
    vector<string> words;
    vector<float> cf;
    words.push_back("w1");
    words.push_back("w2");
    cf.push_back(1.0);
    cf.push_back(2.1);
    dt.box=box;
    dt.words=words;
    dt.confs=cf;
    dt1.box=box;
    dt1.words=words;
    dt1.confs=cf;

    vector<DecodedText> dtr;
    dtr.push_back(dt);
    dtr.push_back(dt1);
    op.box=box;
    op.text_vec=dtr;
    return op;
}
