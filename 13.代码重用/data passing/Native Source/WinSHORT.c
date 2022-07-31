#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinSHORT(SHORT input, SHORT *output);
_declspec(dllexport) void WinSHORT(SHORT input, SHORT *output)
{
  *output = input + input;
}
