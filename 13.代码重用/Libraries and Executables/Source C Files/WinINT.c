#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinINT(INT input, INT *output);
_declspec(dllexport) void WinINT(INT input, INT *output)
{
  *output = input * input;
}
