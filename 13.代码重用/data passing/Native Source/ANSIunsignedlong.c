#include "extcode.h"

_declspec(dllexport) void ANSIunsignedlong(unsigned long input,
                                           unsigned long *output);
_declspec(dllexport) void ANSIunsignedlong(unsigned long input,
                                           unsigned long *output)
{
  *output = input * input;
}
