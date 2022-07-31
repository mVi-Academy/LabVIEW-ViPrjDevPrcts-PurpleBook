#include "extcode.h"

_declspec(dllexport) void ANSIshort(short input, short *output);
_declspec(dllexport) void ANSIshort(short input, short *output)
{
  *output = input + input;
}
