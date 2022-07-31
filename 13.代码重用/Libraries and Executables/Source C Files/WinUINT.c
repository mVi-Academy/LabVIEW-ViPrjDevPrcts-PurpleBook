#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinUINT(UINT input, UINT *output);
_declspec(dllexport) void WinUINT(UINT input, UINT *output)
{
  *output = input * input;
}
