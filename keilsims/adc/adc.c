#include <REG51F020.h>

// Prototypes
void delay(unsigned int);
void init_timer2 (void) ;
void initialize(void) ;
void write_adc(void) ; 


#define adc1 P0
#define adc2 P3

sbit write = P2 ^ 0;
sbit channel =P2^1;


int main()
{
	initialize();
  init_timer2();
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
	write = 0;
	write = 1;
	
}

void initialize(void)
{
	EA = 0; // Disable global interrupts
	
//	// make port 0 as input
	adc1 = 0xff;
	adc2 = 0xff;

	// config port 2
	P2 = 0xfc;
	
	//IT0 = 1; // Configure interrupt 0 for falling edge on /INT0 (P3.2)
	//EX0 = 1; // Enable EX0 Interrupt
	
	//IT1 = 1; // Configure interrupt 1 for falling edge on /INT1 (P3.3)
	//EX1 = 1; // Enable EX1 Interrupt

	WDTCN = 0xde; // Disable watchdog timer
	WDTCN = 0xad;
}

void init_timer2 (void)
{
	// uses system clock DIV BY 12
	CKCON = 0x00; // Define clock (T2M). Timer 2
	T2CON = 0x00;
	// Init reload values in the Capture registers
	RCAP2H = 0xFD;
	RCAP2L = 0x00;
	// count register set to reload immediately 
	TL2 = 0xff;
	TH2 = 0xff;
	// disable timer2 interrupt
	ET2 = 1;
	T2CON = 0x04; // Start Timer2 by setting TR2 (T2CON.2)
}

void ISR_timer2 (void) interrupt 5
{
	TF2 = 0;
	write_adc();
	if(channel==1)
	{
	P1 = adc1 ; 
	}
	else
	{
		P1=adc2;
	}
	
//	data = adc; 
//	P1 = ~ data ; 
}