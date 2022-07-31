#include "extcode.h"

_declspec(dllexport) void LVcmplxExt(cmplxExt *input, cmplxExt *output);
_declspec(dllexport) void LVcmplxExt(cmplxExt *input, cmplxExt *output)
{
  output->re.mhi = input->re.mhi;
  output->re.mlo = input->re.mlo;
  output->im.mhi = input->im.mhi;
  output->im.mlo = input->im.mlo;
  output->re.e = input->re.e + 1;
  output->im.e = input->im.e + 1;
}
