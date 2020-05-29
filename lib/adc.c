#include "adc.h"

void init_adc(void)
{
    // Ports Configurations
    EA = 0 ;
    adc = 0;
    P3 = 0xfc;

    WDTCN = 0xde; // Disable watchdog timer
    WDTCN = 0xad;
}

void init_timer (void)
{
    // Timer Configurations
    CKCON = 0x00;
    T2CON = 0x00;
    RCAP2H = 0xFD;
    RCAP2L = 0x00;
    TL2 = 0xff;
    TH2 = 0xff;
    ET2 = 1;
    T2CON = 0x04;
}

void adc_fetch(void)
{
    write = 0;
    write = 1;
}
