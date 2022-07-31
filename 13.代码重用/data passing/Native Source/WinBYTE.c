#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinBYTE(BYTE input, BYTE *output);
_declspec(dllexport) void WinBYTE(BYTE input, BYTE *output)
{
  *output = input & 0xAA; /*Binary: 10101010*/
}
