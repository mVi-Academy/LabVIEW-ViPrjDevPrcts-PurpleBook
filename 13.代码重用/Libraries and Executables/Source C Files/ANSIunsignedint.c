#include "extcode.h"

_declspec(dllexport) void ANSIunsignedint(unsigned int input,
                                          unsigned int *output);
_declspec(dllexport) void ANSIunsignedint(unsigned int input,
                                          unsigned int *output)
{
  *output = input * input;
}
