#include "extcode.h"

_declspec(dllexport) void ANSIint(int input, int *output);
_declspec(dllexport) void ANSIint(int input, int *output)
{
  *output = input * input;
}
