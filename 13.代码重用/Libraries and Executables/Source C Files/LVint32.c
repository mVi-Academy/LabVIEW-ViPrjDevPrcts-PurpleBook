#include "extcode.h"

_declspec(dllexport) void LVint32(int32 input, int32 *output);
_declspec(dllexport) void LVint32(int32 input, int32 *output)
{
  *output = input * input;
}
