//LCD 4 Bit Driver

#include<lpc21xx.h>
#include"header.h"

#define RS (1<<17) //P1.17-->RS
#define RW (1<<18) //P1.18-->RW
#define EN (1<<19) //P1.19-->EN

void lcd4bit_data(u8 data)
{
	u32 temp;
	
	//Sending higher 4 bits
	IOCLR1=0x00FE0000; //Clearing P1.17-P1.23
	temp=(data&0xF0)<<16; //Extracting higher nibble
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
	
	//Sending lower 4 bits
	IOCLR1=0x00FE0000; //Clearing P1.17-P1.23
	temp=(data&0x0F)<<20; //Extracting lower nibble
	IOSET1=temp;
	IOSET1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}

void lcd4bit_cmd(u8 cmd)
{
	u32 temp;
	
	//Sending higher 4 bits
	IOCLR1=0x00FE0000; //Clearing P1.17-P1.23
	temp=(cmd&0xF0)<<16; //Extracting higher nibble
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
	
	//Sending lower 4 bits
	IOCLR1=0x00FE0000; //Clearing P1.17-P1.23
	temp=(cmd&0x0F)<<20; //Extracting lower nibble
	IOSET1=temp;
	IOCLR1=RS;
	IOCLR1=RW;
	IOSET1=EN;
	delay_ms(2);
	IOCLR1=EN;
}

void lcd4bit_init(void)
{
	IODIR1|=0x00FE0000; //set P1.17-P1.23 as o/p dir
	PINSEL2=0;  //set P1 as GPIO
	
	lcd4bit_cmd(0x02); 
	lcd4bit_cmd(0x03);
	lcd4bit_cmd(0x28);
	lcd4bit_cmd(0x0E);
	lcd4bit_cmd(0x01);
}

void lcd4bit_string(s8 *ptr)
{
	while(*ptr != 0)
	{
		lcd4bit_data(*ptr);
		ptr++;
		delay_ms(50);
	}
}
