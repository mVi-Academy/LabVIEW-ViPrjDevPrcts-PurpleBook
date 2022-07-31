
// CIN Source File
// This CIN source file is dessigned for the project for Base31
#include "extcode.h"
CIN MgErr CINRun (uInt8 **src1Pixels,  uInt8 **src2Pixels,  
				uInt8 **dstPixels,uInt8 **tempPixels, 
				uInt8 *black_gray_thres,uInt8 *light_gray_thres,
				uInt8 *flash_gray_thres,uInt8 *flickery_gray_thres,
				uInt32 *black_size_thres,uInt32 *light_size_thres,
				uInt32 *flash_size_thres,uInt32 *flickery_size_thres,
				LVBoolean *black, LVBoolean *light,LVBoolean *flash,
				LVBoolean *flickery,uInt16 *test);
CIN MgErr CINRun(uInt8 **src1Pixels,  uInt8 **src2Pixels,
				uInt8 **dstPixels,uInt8 **tempPixels, 
				uInt8 *black_gray_thres,uInt8 *light_gray_thres,
				uInt8 *flash_gray_thres,uInt8 *flickery_gray_thres,
	            uInt32 *black_size_thres,uInt32 *light_size_thres,
				uInt32 *flash_size_thres,uInt32 *flickery_size_thres,
				LVBoolean *black, LVBoolean *light,LVBoolean *flash,
				LVBoolean *flickery,uInt16 *test)
{	
	uInt8* src1PixPtr = *src1Pixels;
	uInt8* src2PixPtr = *src2Pixels;
	uInt8* dstPixPtr = *dstPixels;
	uInt8* tempPixPtr= *tempPixels;
	
	long value;
	int xRes = 576, yRes = 576;
	unsigned long sum_light=0,sum_black=0,sum_flash=0,sum_flickery=0,sum_gray=0;

	/*****************************************************************/
	while (yRes--)
	{
		xRes = 576;
		while (xRes--)
		{
			value = *src1PixPtr++ - *src2PixPtr++;
			sum_gray=sum_gray+value;
			if(value < -(*black_gray_thres))    
				*tempPixPtr = 128;		//0x10000000
			else if(value > *light_gray_thres)
				*tempPixPtr = 160;		//0x10100000
			else if(value > *flash_gray_thres)
				*tempPixPtr = 80;		//0x01010000
			else if(value > *flickery_gray_thres)       
		     	*tempPixPtr = 40;		//0x00101000
			else
				*tempPixPtr = 0;	
			tempPixPtr++ ;
		}
		src1PixPtr += 16;  
		src2PixPtr += 16;
		tempPixPtr += 16;
	}
		*test= sum_gray;
	/******************************************************/	
	yRes=574;
	dstPixPtr+=593;		
	tempPixPtr= *tempPixels;
	tempPixPtr+=593;
	while (yRes--)
	{   		
		xRes =574;
		while(xRes--)
		{	
			value=*dstPixPtr= *(tempPixPtr-593) & *(tempPixPtr-592) & *(tempPixPtr-591) &
			*(tempPixPtr-1) & *(tempPixPtr+1) & *(tempPixPtr+591)&
			*(tempPixPtr+592) & *(tempPixPtr+593) & *tempPixPtr; 

		    if(value ==128)		sum_black++;
			if(value ==40)		sum_flickery++;
			if(value == 80)		sum_flash++;
			if(value == 160)	sum_light++;
			dstPixPtr++;
		    tempPixPtr++;
		}
		tempPixPtr += 18;
		dstPixPtr += 18;
	}

	/******************************************************/
		if(sum_flickery+sum_flash+sum_light> *flickery_size_thres) 
			*flickery=1;  
		else
			*flickery=0;

		if(sum_flash+sum_light > *flash_size_thres) 
			*flash=1;  
		else
			*flash=0;

		if(sum_light > *light_size_thres) 
			*light=1;  
		else
			*light=0;

		if(sum_black > *black_size_thres)
			*black=1;
		else
			*black=0;
								
	return noErr;
}