#include "extcode.h"
#include <windows.h>

_declspec(dllexport) void WinCHAR(CHAR *input, PCHAR output);
_declspec(dllexport) void WinCHAR(CHAR *input, PCHAR output)
{
  size_t i, j;

  /* Reverse "i" characters. Assume output already has memory. */
  for(i = strlen(input), j = 0; i > 0; j++)
  {
    output[j] = input[--i];
  }
}
