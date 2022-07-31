#include "extcode.h"

#pragma pack(1)

/* LabVIEW created typedef */
typedef struct {
	double DBL;
	char Boolean;
	int I32;
	} TD1;

_declspec(dllexport) void CLUSTERBytePack1(TD1 *input, TD1 *output);
_declspec(dllexport) void CLUSTERBytePack1(TD1 *input, TD1 *output)
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

#pragma pack(8)

/* LabVIEW created typedef */
typedef struct {
	double DBL;
	char Boolean;
	int I32;
	} TD8;

_declspec(dllexport) void CLUSTERBytePack8(TD8 *input, TD8 *output);
_declspec(dllexport) void CLUSTERBytePack8(TD8 *input, TD8 *output)
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

#pragma pack()