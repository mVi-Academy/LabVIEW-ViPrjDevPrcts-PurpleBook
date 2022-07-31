#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinSIZE_T(SIZE_T input, SIZE_T *output);
_declspec(dllexport) void WinSIZE_T(SIZE_T input, SIZE_T *output)
{
  *output = input * input;
}
