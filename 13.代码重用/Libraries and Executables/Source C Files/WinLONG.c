#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinLONG(LONG input, LONG *output);
_declspec(dllexport) void WinLONG(LONG input, LONG *output)
{
  *output = input * input;
}
