/*
Analog to Digital Filter.

by :
	- Ahmad Alnoubi
	- Ahmad Mahdy 
	- Ahmad Khaled
	- Ahmad Abdelmageed
	- Sayed Abdullah

The project files includes:
	- Proteus Simulation files 
	- Kile Simulation files 
	- Our Code Files 
*/
#include <REG51F020.h>
#include "FILTER.h"

// Prototypes
void delay(unsigned int);
void init_timer1 (void) ;
void initialize(void) ;
void write_adc(void) ; 


#define adc1 P0
#define adc2 P3

sbit write = P2 ^ 0;
sbit channel =P2^1;


int main()
{
	RESET_REG();
	initialize();
  init_timer1();
	write = 0;
	EA = 1 ; 
	
	while(1){}
	return 0;
}


/*Function to Provide delay*/
void delay(unsigned int time)
{
    unsigned int i;
    for(i=0; i<=time; i++);
}

void write_adc(void)
{
	// Apply a low to high edge
	write = 0;
	write = 1;
	
}

void initialize(void)
{
	// Disable global interrupts
	EA = 0; 
	
//	// make port 0 as input
	adc1 = 0xff;
	adc2 = 0xff;

	// config port 2
	P2 = 0xfc;

	WDTCN = 0xde; // Disable watchdog timer
	WDTCN = 0xad;
}

void init_timer1 (void)
{
	// uses system clock DIV BY 12
//	CKCON = 0x00; // Define clock (T2M). Timer 2
//	T0CON = 0x00;
//	
//	// Init reload values in the Capture registers
//	RCAP2H = 0xFD;
//	RCAP2L = 0x00;
//	
//	// count register set to reload immediately 
//	TL0= 0xff;
//	TH0= 0xff;
//	
//	// disable timer2 interrupt
//	ET0 = 1;
//	T0CON = 0x04; // Start Timer2 by setting TR2 (T2CON.2)
	
		TMOD = 0x01;       //Timer0 mode 1 
    TH0 = 0xfc;        //Load the timer value
    TL0 = 0xff;
    TR0 = 1;           //turn ON Timer zero
    ET0 = 1;           //Enable TImer0 Interrupt
    EA = 1;            //Enable Global Interrupt bit
}

void ISR_timer2 (void) interrupt 1
{
	TF0 = 0;
	write_adc();
//	FLITER_CTR = 6 ;
//	inputSignal[0] = adc1;
//	HPF();
//	P1 = outputSignal[0];
//	SHIFT_REG(FLITER_CTR);
		P1 = adc1; 
	
//	data = adc; 
//	P1 = ~ data ; 
}