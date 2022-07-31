#include "extcode.h"

_declspec(dllexport) void LVint16(int16 input, int16 *output);
_declspec(dllexport) void LVint16(int16 input, int16 *output)
{
  *output = input + input;
}
