#ifndef TEXTDETECTOR_DECODEDTEXT
#define TEXTDETECTOR_DECODEDTEXT

#include <vector>
#include <string>

#include "box.hpp"

struct DecodedText
{
  Box box;
  std::vector<std::string> words;
  std::vector<float> confs;
};

#endif
