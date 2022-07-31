#include "extcode.h"

_declspec(dllexport) void LVfloat64(float64 input, float64 *output);
_declspec(dllexport) void LVfloat64(float64 input, float64 *output)
{
  *output = input * input;
}
