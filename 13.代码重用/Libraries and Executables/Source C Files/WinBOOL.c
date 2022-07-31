#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinBOOL(BOOL input, BOOL *output);
_declspec(dllexport) void WinBOOL(BOOL input, BOOL *output)
{
  if(input)
    *output = FALSE;
  else
    *output = TRUE;
}
