#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinCOLORREF(COLORREF input, COLORREF *output);
_declspec(dllexport) void WinCOLORREF(COLORREF input, COLORREF *output)
{
  if(input == 0x000000) /* black */
    *output = 0xFF0000; /* blue */
  else
    *output = 0x00FF00; /* green */
}
