#include "extcode.h"
#include <string.h>

_declspec(dllexport) void ANSIunsignedchar(unsigned char *input,
                                           unsigned char *output);
_declspec(dllexport) void ANSIunsignedchar(unsigned char *input, 
                                           unsigned char *output)
{
  size_t i, j;

  /* Reverse "i" characters. Assume output already has memory. */
  for( i = strlen( input ), j = 0; i > 0; j++ )
  {
    output[j] = input[--i];
  }
}
