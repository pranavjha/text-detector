#include "main.h"

#include <iostream>

using namespace std;

string Ocr (string path, bool detectRegion) {
    if(detectRegion) {
        return path;
    } else {
        return ("skip" + path);
    }
}
