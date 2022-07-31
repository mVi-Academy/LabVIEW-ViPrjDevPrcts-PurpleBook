#include "extcode.h"

_declspec(dllexport) void LVint8(int8 input, int8 *output);
_declspec(dllexport) void LVint8(int8 input, int8 *output)
{
  *output = input + input;
}
