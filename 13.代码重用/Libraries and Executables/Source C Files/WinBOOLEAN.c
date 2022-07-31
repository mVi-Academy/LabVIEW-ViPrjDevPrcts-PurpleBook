#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinBOOLEAN(BOOLEAN input,
                                     BOOLEAN *pinput,
                                     PBOOLEAN output);
_declspec(dllexport) void WinBOOLEAN(BOOLEAN input,
                                     BOOLEAN *pinput,
                                     PBOOLEAN output)
{
  if(input && *pinput)
    *output = FALSE;
  else
    *output = TRUE;
}
