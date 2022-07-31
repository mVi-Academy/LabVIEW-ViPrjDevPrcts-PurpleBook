/* Call Library source file */
#include "extcode.h"

extern "C" __declspec(dllexport) int32_t __cdecl arraySum(float ptr[], int32_t Size, float* Sum);

__declspec(dllexport) int32_t __cdecl arraySum(float ptr[], int32_t Size, float* Sum)
{
	/* Insert code here */
	int i;
	float tmpSum = 0;
	if (ptr != NULL)
	{
		for (i = 0; i < Size; i++)
			tmpSum = tmpSum + ptr[i];
	}
	else
		return (1);
	*Sum = tmpSum;
	return (0);
}