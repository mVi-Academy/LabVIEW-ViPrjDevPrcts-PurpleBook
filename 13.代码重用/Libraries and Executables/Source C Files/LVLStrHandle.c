#include "extcode.h"
#include <string.h>

/* Handle "cnt" field is int32 so max length is INT32_MAX. */
#define MaxHandleStringLength INT32_MAX

_declspec(dllexport) void LVLStrHandle(LStrHandle input, LStrHandle output);
_declspec(dllexport) void LVLStrHandle(LStrHandle input, LStrHandle output)
{
  int32 len;
  uInt32 i, j, stringLength;

  len = (*input)->cnt;
  /* If we really have a handle, make sure it has enough room.. */
  if ( !DSCheckHandle( output )) {
	stringLength = len * 2;
	if ( stringLength > MaxHandleStringLength ) {
		stringLength = MaxHandleStringLength;
	}

	if (( *output )->cnt < stringLength ) {
	  /* Adjust the handle size to hold everything we want to put in it */
	  DSSetHandleSize(( void* )output, stringLength );
	}
  
    if ( !DSCheckHandle( output )) {
      strncpy((*output)->str, (*input)->str, len);
      /* Reverse "i" characters. */
      for ( i = len, j = 0; ( i > 0 ) && ( j < ( stringLength - len )); j++ )
      {
        (*output)->str[j + len] = (*input)->str[--i];
      }
      (*output)->cnt = stringLength;
    }
  }
}
