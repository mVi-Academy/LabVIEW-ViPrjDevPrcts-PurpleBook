#include "extcode.h"
#include <math.h>

/* LabVIEW created typedefs */
typedef struct {
	int32 dimSize;
	double elt[1];
	} TD1;
typedef TD1 **TD1Hdl;

typedef struct {
	int32 dimSize;
	long elt[1];
	} TD2;
typedef TD2 **TD2Hdl;


_declspec(dllexport) void ARRAY1DHandle(TD1Hdl input, TD2Hdl output);
_declspec(dllexport) void ARRAY1DHandle(TD1Hdl input, TD2Hdl output)
{
  int i;

  /* Calculate the floor of the square of each value. */
  for(i = 0; i < (*input)->dimSize; i++)
  {
    (*output)->elt[i] = (int)floor((*input)->elt[i] * (*input)->elt[i]);
  }
}
