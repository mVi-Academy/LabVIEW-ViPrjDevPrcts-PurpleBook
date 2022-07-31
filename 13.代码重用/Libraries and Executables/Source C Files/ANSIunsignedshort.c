#include "extcode.h"

_declspec(dllexport) void ANSIunsignedshort(unsigned short input,
                                            unsigned short *output);
_declspec(dllexport) void ANSIunsignedshort(unsigned short input,
                                            unsigned short *output)
{
  *output = input + input;
}
