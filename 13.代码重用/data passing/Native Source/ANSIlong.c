#include "extcode.h"

_declspec(dllexport) void ANSIlong(long input, long *output);
_declspec(dllexport) void ANSIlong(long input, long *output)
{
  *output = input * input;
}
