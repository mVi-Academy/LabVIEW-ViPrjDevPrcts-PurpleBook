#include "extcode.h"

_declspec(dllexport) void LVcmplx128(cmplx128 *input, cmplx128 *output);
_declspec(dllexport) void LVcmplx128(cmplx128 *input, cmplx128 *output)
{
  output->re = (input->re * input->re) - (input->im * input->im);
  output->im = (float64)2.0 * (input->re * input->im);
}
