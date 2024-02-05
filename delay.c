//Delay 

#include<lpc21xx.h>
#include"header.h"

void delay_sec(u32 sec)
{
	s32 a[]={15,60,30,0,15};
	u32 pclk=0;
	/*if(VPBDIV==3)
		lcd4_string("Error...");*/
	pclk=a[VPBDIV]*1000000;
	
	T0PC=0;
	T0PR=pclk-1;
	T0TC=0;
	T0TCR=1;
	while(T0TC<sec);
	T0TCR=0;
}

void delay_ms(u32 ms)
{
	s32 a[]={15,60,30,0,15};
	u32 pclk=0;
	/*if(VPBDIV==3)
		lcd4_string("Error...");*/
	pclk=a[VPBDIV]*1000;
	
	T0PC=0;
	T0PR=pclk-1;
	T0TC=0;
	T0TCR=1;
	while(T0TC<ms);
	T0TCR=0;
}
