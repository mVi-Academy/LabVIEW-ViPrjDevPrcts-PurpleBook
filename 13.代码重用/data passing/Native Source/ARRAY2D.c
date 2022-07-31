#include "extcode.h"

_declspec(dllexport) void ARRAY2D(double *array,
                                  int array_length_row,
                                  int array_length_col);
_declspec(dllexport) void ARRAY2D(double *array,
                                  int array_length_row,
                                  int array_length_col)
{
  int i, j;

  for(i = 0; i < array_length_row; i++)
  {
    for(j = 0; j < array_length_col; j++)
    {
      array[(i * array_length_col) + j] = array[(i * array_length_col) + j] *
                                          array[(i * array_length_col) + j];
    }
  }
}
