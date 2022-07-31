#include "extcode.h"

_declspec(dllexport) void LVfloat32(float32 input, float32 *output);
_declspec(dllexport) void LVfloat32(float32 input, float32 *output)
{
  *output = input * input;
}
