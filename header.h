typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

//Delay
extern void delay_sec(u32);
extern void delay_ms(u32);

//LCD 4 Bit
extern void lcd4bit_data(u8);
extern void lcd4bit_cmd(u8);
extern void lcd4bit_init(void);
extern void lcd4bit_string(s8 *);

//UART0
extern void uart0_init(u32);
extern void uart0_tx(u8);
extern u8 uart0_rx(void);
extern void uart0_tx_string(u8 *);
extern void uart0_rx_string(s8 *,s32);
