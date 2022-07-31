#include "extcode.h"
#include <string.h>

_declspec(dllexport) void LVCStr(CStr input, CStr output);
_declspec(dllexport) void LVCStr(CStr input, CStr output)
{
  size_t i, j;

  /* Reverse "i" characters. Assume output already has memory. */
  for(i = strlen(input), j = 0; i > 0; j++)
  {
    output[j] = input[--i];
  }
}
