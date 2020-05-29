#ifndef ADC_ADC_H
#define ADC_ADC_H
#include "REG51F020.h"

sfr adc = 0x80;
sbit write = P3 ^ 0;

void adc_fetch(void) ;
void init_adc(void);
void init_timer (void);


#endif //ADC_ADC_H
