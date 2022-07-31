#include "extcode.h"
#include <string.h>

/* Typedefs to adjust LabVIEW data */
/* NOT CREATED by LabVIEW */
typedef struct {
	float64 DBL;
	uChar string[51];
  int32 array[50];
	} TD1;

_declspec(dllexport) void CLUSTERSimpleS_A(TD1 *input, TD1 *output);

_declspec(dllexport) void CLUSTERSimpleS_A(TD1 *input, TD1 *output)
{
  size_t i, j;

  output->DBL = input->DBL * input->DBL;

  /* Reverse "i" characters. Assume output already has memory. */
  for(i = strlen(input->string), j = 0; i > 0; j++)
  {
    output->string[j] = input->string[--i];
  }

  for(i = 0; i < 50; i++)
  {
    output->array[i] = input->array[i] * 2;
  }
}