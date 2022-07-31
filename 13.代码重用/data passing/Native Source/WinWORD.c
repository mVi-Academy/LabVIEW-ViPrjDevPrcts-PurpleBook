#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinWORD(WORD input, WORD *output);
_declspec(dllexport) void WinWORD(WORD input, WORD *output)
{
  *output = input + input;
}
