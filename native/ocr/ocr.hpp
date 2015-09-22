#include  "opencv2/text.hpp"
#include  "opencv2/highgui.hpp"
#include  "opencv2/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include  <vector>
#include  <iostream>
#include  <iomanip>
#include "opencv/cv.h"

using namespace std;
using namespace cv;
using namespace cv::text;

OutputOcr Ocr(std::string);
OutputOcr Ocr(std::string, Rect box);
