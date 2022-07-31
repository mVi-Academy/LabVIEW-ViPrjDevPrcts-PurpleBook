#include "extcode.h"

/* LabVIEW created typedef */
typedef struct {
	int32 dimSizes[2];
	double elt[1];
	} TD1;
typedef TD1 **TD1Hdl;

_declspec(dllexport) void ARRAY2DHandle(TD1Hdl array);
_declspec(dllexport) void ARRAY2DHandle(TD1Hdl array)
{
  int i, j;
  /* dimSizes[0] is the number of rows */
  int numrow = (*array)->dimSizes[0];
  /* dimSizes[1] is the number of columns */
  int numcol = (*array)->dimSizes[1];

  for(i = 0; i < numrow; i++)
  {
    for(j = 0; j < numcol; j++)
    {
      (*array)->elt[(i * numcol) + j] = (*array)->elt[(i * numcol) + j] *
                                         (*array)->elt[(i * numcol) + j];
    }
  }
}
