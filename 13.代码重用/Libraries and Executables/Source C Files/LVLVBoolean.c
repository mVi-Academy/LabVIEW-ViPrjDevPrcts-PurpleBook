#include "extcode.h"

_declspec(dllexport) void LVLVBoolean(LVBoolean input,
                                      LVBoolean *pinput,
                                      LVBoolean *output);
_declspec(dllexport) void LVLVBoolean(LVBoolean input,
                                      LVBoolean *pinput,
                                      LVBoolean *output)
{
  if(input && *pinput)
    *output = FALSE;
  else
    *output = TRUE;
}
