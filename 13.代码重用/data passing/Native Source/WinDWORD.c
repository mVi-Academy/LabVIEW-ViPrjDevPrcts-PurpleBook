#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinDWORD(DWORD input, DWORD *output);
_declspec(dllexport) void WinDWORD(DWORD input, DWORD *output)
{
  *output = input * input;
}
