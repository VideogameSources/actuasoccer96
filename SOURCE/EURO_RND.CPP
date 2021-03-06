#include <stdlib.h>
#include "eurodefs.h"
#include "euro_fxd.h"
#include "euro.equ"
#include "euro_sym.h"
#include "euro_def.h"
#include "euro_var.h"

//********************************************************************************************************************************

		//浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融 
		//�                                                                        �
		//� Random number method 1 -> originates from Mike Hart, slightly modified �
		//�                                                                        �
		//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕 
	
short GetRnd1()
	{
		long rnd = EUROseed1;

		if ( rnd == 0 )
			rnd = 0x024272;
		if ( rnd > 2147483648 )
		{
			rnd+= rnd;		
			rnd^= 0x01d872b45;
		}			
	
		else
			rnd+= rnd;		

		EUROseed1 = rnd+7;
		return( (short)EUROseed1 );
	}

//********************************************************************************************************************************

		//浜様様様様様様様様様様融 
		//�                      �
		//� Watcom Random number �
		//�                                                             �
		//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様� 
	
unsigned short GetRnd2()
	{
		return((short)rand());
	}

//********************************************************************************************************************************

		//浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様� 
		//�                                                             �
		//� Random number method 3 -> originates from Zool GameGear Z80 �
		//�                                                             �
		//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様� 
	
unsigned short GetRnd3()
	{
		short	t2 = EUROseed3*32;
		short	t3 = (EUROseed3*16)-EUROseed3;
		t3	   = ((((( t3-t2 ) *8 )+EUROseed3)*4)+EUROseed3)+0x01d872b45;		
		EUROseed3  = t3;
		return(t3);
	}

//********************************************************************************************************************************
