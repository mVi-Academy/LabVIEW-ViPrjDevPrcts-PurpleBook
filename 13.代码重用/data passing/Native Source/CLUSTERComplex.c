#include "extcode.h"
#include <string.h>
#include <stdlib.h>

/* Handle "cnt" field is int32 so max length is INT32_MAX. */
#define MaxHandleStringLength INT32_MAX

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
	uChar *string;
  int32 array_size;
  int32 *array;
	} TD1;

int CLUSTERComplexOrig(TD1 *input, TD1 *output); /* see below */
_declspec(dllexport) void CLUSTERComplex(TD2 *input, TD2 *output);
_declspec(dllexport) void CLUSTERComplex(TD2 *input, TD2 *output)
{
  TD1 datain, dataout;
  int i;
  size_t realStringLength;

  /* Prepare LabVIEW data to be called by original function */
  datain.DBL = input->DBL;
  /* Allocate memory for string */
  datain.string = (uChar*)malloc(sizeof(uChar) * ((*(input->String))->cnt + 1));
  /* Error Check that malloc was successful */
  if(datain.string == NULL)
  {
    /* If malloc fails, quit and set error message in string */
    if(noErr == NumericArrayResize(uB, 1, (UHandle*)(&(output->String)), 38))
    {
      strncpy((*(output->String))->str, "Error creating struct for string.",33);
      (*(output->String))->cnt = 33;
    }
    return;
  }
  else
  {
    /* malloc successful so copy string over */
    strncpy(datain.string, (*(input->String))->str, (*(input->String))->cnt);
    datain.string[(*(input->String))->cnt] = '\0';
  }
  /* Allocate memory for array */
  datain.array_size = (*(input->Array))->dimSize;
  datain.array = (int32*)malloc(datain.array_size * sizeof(int32));
  /* Error Check that malloc was successful */
  if(datain.string == NULL)
  {
    /* If malloc fails, quit and set error message in string */
    if(noErr == NumericArrayResize(uB, 1, (UHandle*)(&(output->String)), 37))
    {
      strncpy((*(output->String))->str, "Error creating struct for string.",32);
      (*(output->String))->cnt = 32;
    }
    /* Just in case the previous malloc was successful */
    free(datain.string);
    return;
  }
  else
  {
    /* malloc successful so copy array over */
    for(i = 0; i < (*(input->Array))->dimSize; i++)
    {
      datain.array[i] = (*(input->Array))->Numeric[i];
    }
  }

  /* Call original function */
  if(!CLUSTERComplexOrig(&datain, &dataout))
  {
    /* Take original function data back to LabVIEW format */
    output->DBL = dataout.DBL;
    /* Set new string length */
    realStringLength = strlen( dataout.string );
    if ( realStringLength > ( MaxHandleStringLength - 4 )) {
		realStringLength = MaxHandleStringLength - 4;
	}
    (*(output->String))->cnt = realStringLength;
    /* New string is twice as long so we need to resize the string handle */
    /* This is done using the NumericArrayResize memory manager function */
    NumericArrayResize(uB, 1, (UHandle*)(&(output->String)),
                       4 + realStringLength);
    /* Copy the new string to the LabVIEW cluster */
    strncpy((*(output->String))->str, dataout.string, realStringLength);
    /* The original function does not change the size of the array */
    for(i = 0; i < dataout.array_size; i++)
    {
      (*(output->Array))->Numeric[i] = dataout.array[i];
    }
    (*(output->Array))->dimSize = dataout.array_size;
  }
  else
  {
    /* The original function returned an error so quit and set error message */
    if(noErr == NumericArrayResize(uB, 1, (UHandle*)(&(output->String)), 37))
    {
      strncpy((*(output->String))->str, "Error creating struct for string.",32);
      (*(output->String))->cnt = 32;
    }
  }
  /* Clean up what was allocated */
  free(datain.string);
  free(datain.array);
  free(dataout.string);
  free(dataout.array);
}

/* Reverse and concatenate the input string, square the DBL, and double */
/* each element in the int32 array. Place new values in output */
int CLUSTERComplexOrig(TD1 *input, TD1 *output)
{
  size_t i, j, len;

  /* Square DBL */
  output->DBL = input->DBL * input->DBL;
  /* Get length of input string */
  len = strlen(input->string);
  /* Allocate memory for new string */
  output->string = (uChar*)malloc(sizeof(uChar) * (2 * len + 1));
  if(output->string == NULL)
  {
    /* Error in malloc, return error */
    return -1;
  }
  /* Copy input string to output string */
  strncpy(output->string, input->string, len);
  /* Concatenate the reverse of the original string */
  for(i = len, j = 0; i > 0; j++)
  {
    output->string[j + len] = input->string[--i];
  }
  /* Set the last character to NULL */
  output->string[2 * len] = '\0';
  /* Set the array size */
  output->array_size = input->array_size;
  /* Allocate memory for the new array */
  output->array = (int32*)malloc(sizeof(int32) * output->array_size);
  if(output->array == NULL)
  {
    /* Error in malloc, return error */
    return -1;
  }
  /* Double each element of the input array into output array */
  for(i = 0; i < output->array_size; i++)
  {
    output->array[i] = input->array[i] * 2;
  }
  /* Completed with no error */
  return 0;
}
