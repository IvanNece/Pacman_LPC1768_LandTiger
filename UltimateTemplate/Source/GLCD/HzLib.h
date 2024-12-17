/****************************************Copyright (c)**************************************************                         
**
**                                 http://www.powermcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			HzLib.h
** Descriptions:		None
**				
**------------------------------------------------------------------------------------------------------
** Created by:			AVRman
** Created date:		2010-11-1
** Version:				1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	
** Version:
** Descriptions:							   
********************************************************************************************************/


#ifndef __HZLIB_H
#define __HZLIB_H 

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdint.h>

// Prototipo della funzione delay globale
void delay_ms(uint16_t ms);  

/* Private function prototypes -----------------------------------------------*/
void GetGBKCode(unsigned char* pBuffer,unsigned char * c);

#endif 


/*********************************************************************************************************
      END FILE
*********************************************************************************************************/




