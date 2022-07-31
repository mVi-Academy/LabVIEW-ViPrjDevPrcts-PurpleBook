#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinFLOAT(FLOAT input, FLOAT *output);
_declspec(dllexport) void WinFLOAT(FLOAT input, FLOAT *output)
{
  *output = input * input;
}
