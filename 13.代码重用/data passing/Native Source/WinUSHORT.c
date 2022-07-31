#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinUSHORT(USHORT input, USHORT *output);
_declspec(dllexport) void WinUSHORT(USHORT input, USHORT *output)
{
  *output = input + input;
}
