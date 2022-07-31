#include "extcode.h"

_declspec(dllexport) void ANSIfloat(float input, float *output);
_declspec(dllexport) void ANSIfloat(float input, float *output)
{
  *output = input * input;
}
