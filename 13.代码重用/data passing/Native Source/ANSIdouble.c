#include "extcode.h"

_declspec(dllexport) void ANSIdouble(double input, double *output);
_declspec(dllexport) void ANSIdouble(double input, double *output)
{
  *output = input * input;
}
