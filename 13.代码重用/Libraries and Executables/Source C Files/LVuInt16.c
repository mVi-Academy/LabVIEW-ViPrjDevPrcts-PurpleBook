#include "extcode.h"

_declspec(dllexport) void LVuInt16(uInt16 input, uInt16 *output);
_declspec(dllexport) void LVuInt16(uInt16 input, uInt16 *output)
{
  *output = input + input;
}
