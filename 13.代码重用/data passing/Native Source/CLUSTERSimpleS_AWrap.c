#include "extcode.h"
#include <string.h>

/* LabVIEW created typdefs */
typedef struct {
	int32 dimSize;
	long Numeric[1];
	} TD3;
typedef TD3 **TD3Hdl;

typedef struct {
	double DBL;
	LStrHandle String;
	TD3Hdl Array;
	} TD2;

/* Manually created struct to call original function */
typedef struct {
	float64 DBL;
	uChar string[51];
  int32 array[50];
	} TD1;

void CLUSTERSimpleS_A(TD1 *input, TD1 *output);
_declspec(dllexport) void CLUSTERSimpleS_AWrap(TD2 *input, TD2 *output);
_declspec(dllexport) void CLUSTERSimpleS_AWrap(TD2 *input, TD2 *output)
{
  TD1 datain, dataout;
  int i;
  /* Check if we have more than 50 characters (minus termination) */
  int strcutoff = (*(input->String))->cnt < 51 ? (*(input->String))->cnt : 50;
  /* Check if we have more than 50 array elements */
  int arrcutoff = (*(input->Array))->dimSize < 51 ?
                  (*(input->Array))->dimSize : 50;

  /* Prepare LabVIEW data to be called by original function */
  datain.DBL = input->DBL;
  strncpy(datain.string, (*(input->String))->str, strcutoff);
  for(i = strcutoff; i < 51; i++)
  {
    datain.string[i] = '\0';
  }
  for(i = 0; i < arrcutoff; i++)
  {
    datain.array[i] = (*(input->Array))->Numeric[i];
  }
  /* Use that i is now at first blank index of data.array */
  for(; i < 50; i++)
  {
    datain.array[i] = 0;
  }

  /* Call original function */
  CLUSTERSimpleS_A(&datain, &dataout);

  /* Take original function data back to LabVIEW format */
  /* Do not need to use memory management routines since size of the string */
  /* and size of the array did not change from the original */
  output->DBL = dataout.DBL;
  strncpy((*(output->String))->str, dataout.string, strcutoff);
  (*(output->String))->cnt = strcutoff;
  for(i = 0; i < arrcutoff; i++)
  {
    (*(output->Array))->Numeric[i] = dataout.array[i];
  }
  (*(output->Array))->dimSize = arrcutoff;
}
