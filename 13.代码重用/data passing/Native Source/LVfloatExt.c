#include "extcode.h"

_declspec(dllexport) void LVfloatExt(floatExt *input, floatExt *output);
_declspec(dllexport) void LVfloatExt(floatExt *input, floatExt *output)
{
  output->mhi = input->mhi;
  output->mlo = input->mlo;
  output->e = input->e + 1;
}
