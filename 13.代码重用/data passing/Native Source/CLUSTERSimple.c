#include "extcode.h"

/* LabVIEW created typedef */
typedef struct {
	double DBL;
	long I32;
	char Boolean;
	} TD1;

_declspec(dllexport) void CLUSTERSimple(TD1 *input, TD1 *output);

_declspec(dllexport) void CLUSTERSimple(TD1 *input, TD1 *output)
{
  output->DBL = input->DBL * input->DBL;
  output->I32 = input->I32 / 2;
  if(input->Boolean)
  {
    output->Boolean = FALSE;
  }
  else
  {
    output->Boolean = TRUE;
  }
}