#include "extcode.h"

_declspec(dllexport) void ARRAY3D(double *array,
                                  int array_length_page,
                                  int array_length_row,
                                  int array_length_col);
_declspec(dllexport) void ARRAY3D(double *array,
                                  int array_length_page,
                                  int array_length_row,
                                  int array_length_col)
{
  int i,j,k;
  int ps = array_length_row * array_length_col;
  double temp;

  for(i = 0; i < array_length_row; i++)
  {
    for(j = 0; j < array_length_col; j++)
    {
      temp = 0.0;
      for(k = 0; k < array_length_page; k++)
      {
        if(k == array_length_page - 1)
        {
          array[(k * ps) + (i * array_length_col) + j] = temp;
        }
        else
        {
          temp += array[(k * ps) + (i * array_length_col) + j];
        }
      }
    }
  }
}