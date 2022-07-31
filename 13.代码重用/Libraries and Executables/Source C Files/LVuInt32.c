#include "extcode.h"

_declspec(dllexport) void LVuInt32(uInt32 input, uInt32 *output);
_declspec(dllexport) void LVuInt32(uInt32 input, uInt32 *output)
{
  *output = input * input;
}
