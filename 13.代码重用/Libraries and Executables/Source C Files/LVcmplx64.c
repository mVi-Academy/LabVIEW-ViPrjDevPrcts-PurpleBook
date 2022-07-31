#include "extcode.h"

_declspec(dllexport) void LVcmplx64(cmplx64 *input, cmplx64 *output);
_declspec(dllexport) void LVcmplx64(cmplx64 *input, cmplx64 *output)
{
  output->re = (input->re * input->re) - (input->im * input->im);
  output->im = (float32)2.0 * (input->re * input->im);
}
