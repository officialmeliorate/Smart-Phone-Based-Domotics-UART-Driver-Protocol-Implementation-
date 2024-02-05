//Smart Phone Based Home Automation Using Bluetooth(HC-05 & LPC2129 uc)

#include"header.h"
#include<lpc21xx.h>
//#include<ctype.h> //For implementing tolower() & toupper()

#define LED (1<<17) //LED-->P0.17
#define FAN (1<<18) //Fan-->P0.18

int main()
{
	s8 cmd;
	lcd4bit_init();
	uart0_init(9600);
	IODIR0=LED|FAN;
	while(1)
	{
		lcd4bit_cmd(0x01);
		lcd4bit_cmd(0x80);
		uart0_tx_string("\r\nSmart Phone Based Home Automation\r\n");
		lcd4bit_string("Home Automation");
		lcd4bit_cmd(0xC0);
		uart0_tx_string("\r\nMenu...\r\n");
		uart0_tx_string("\r\nPress A-->LED ON\r\nPress B-->LED OFF\r\nPress C-->FAN ON\r\nPress D-->FAN OFF\r\n");
		cmd=uart0_rx();
		uart0_tx(cmd);  //loopback
		
		switch(cmd)
		{
			case 'A':IOSET0=LED; uart0_tx_string("\r\nLED ON...\r\n"); lcd4bit_string("LED ON"); break;
			case 'B':IOCLR0=LED; uart0_tx_string("\r\nLED OFF...\r\n"); lcd4bit_string("LED OFF"); break;
			case 'C':IOSET0=FAN; uart0_tx_string("\r\nFAN ON...\r\n"); lcd4bit_string("FAN ON"); break;
			case 'D':IOCLR0=FAN; uart0_tx_string("\r\nFAN OFF...\r\n"); lcd4bit_string("FAN OFF"); break;
			
			default: uart0_tx_string("\r\nInvalid Input\r\n");
		}
	}
}
