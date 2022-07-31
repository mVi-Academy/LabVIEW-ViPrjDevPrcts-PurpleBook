#include "extcode.h"

_declspec(dllexport) void LVuInt8(uInt8 input, uInt8 *output);
_declspec(dllexport) void LVuInt8(uInt8 input, uInt8 *output)
{
  *output = input +input;
}
