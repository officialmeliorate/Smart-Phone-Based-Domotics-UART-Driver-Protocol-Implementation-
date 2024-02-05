//uart0 driver code

#include<lpc21xx.h>
#include"header.h"

//For initializing uart0
void uart0_init(u32 baud)
{
	int a[]={15,60,30,0,15};
	u32 pclk=a[VPBDIV]*1000000;
	u32 result=0;
	result=pclk/(16*baud);
	
	PINSEL0|=0x5; //p0.0-->Tx & p0.1-->Rx
	U0LCR=0x83;
	U0DLL=result&0xFF;
	U0DLM=(result>>8)&0xFF;
	U0LCR=0x03;
}


//For sending 1 byte data
#define THRE ((U0LSR>>5)&1)
void uart0_tx(u8 data)
{
	U0THR=data;
	while(THRE==0);
}


//For receiving 1 byte data
#define RDR (U0LSR&1)
u8 uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}

//For sending string
void uart0_tx_string(u8 *ptr)
{
	while(*ptr != 0)
	{
		U0THR= *ptr;
		while(THRE==0);
		ptr++;
	}
}

//For receiving string
void uart0_rx_string(s8 *ptr,s32 max_bytes)
{
	int i;
	for(i=0 ; i<max_bytes ; i++)
	{
		while(RDR==0);
		ptr[i]=U0RBR;
		while(ptr[i]=='\r')  //if enter key pressed
			break;
  }
	ptr[i]='\0';
}
