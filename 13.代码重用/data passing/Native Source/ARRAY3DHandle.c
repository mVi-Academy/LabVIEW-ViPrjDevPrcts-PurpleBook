#include "extcode.h"

/* LabVIEW created typdef */
typedef struct {
	int32 dimSizes[3];
	double elt[1];
	} TD1;
typedef TD1 **TD1Hdl;

_declspec(dllexport) void ARRAY3DHandle(TD1Hdl array);
_declspec(dllexport) void ARRAY3DHandle(TD1Hdl array)
{
  int i,j,k;
  /* dimSizes[0] is the number of pages */
  int numpag = (*array)->dimSizes[0];
  /* dimSizes[1] is the number of rows */
  int numrow = (*array)->dimSizes[1];
  /* dimSizes[2] is the number of columns */
  int numcol = (*array)->dimSizes[2];
  int ps = numrow * numcol;
  double temp;

  for(i = 0; i < numrow; i++)
  {
    for(j = 0; j < numcol; j++)
    {
      temp = 0.0;
      for(k = 0; k < numpag ; k++)
      {
        if(k == numpag - 1)
        {
          (*array)->elt[(k * ps) + (i * numcol) + j] = temp;
        }
        else
        {
          temp += (*array)->elt[(k * ps) + (i * numcol) + j];
        }
      }
    }
  }
}