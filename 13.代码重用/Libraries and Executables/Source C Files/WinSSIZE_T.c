#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinSSIZE_T(SSIZE_T input, SSIZE_T *output);
_declspec(dllexport) void WinSSIZE_T(SSIZE_T input, SSIZE_T *output)
{
  *output = input * input;
}
