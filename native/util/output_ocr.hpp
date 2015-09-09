#ifndef TEXTDETECTOR_OUTPUTOCR
#define TEXTDETECTOR_OUTPUTOCR

#include <vector>

#include "box.hpp"
#include "decoded_text.hpp"

struct OutputOcr
{
  Box box;
  std::vector<DecodedText> text_vec;  
};

#endif
