#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinULONG(ULONG input, ULONG *output);
_declspec(dllexport) void WinULONG(ULONG input, ULONG *output)
{
  *output = input * input;
}
