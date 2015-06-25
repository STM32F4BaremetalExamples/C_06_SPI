#include "stm32f4xx.h"                  // Device header
#include "spi.h"

//MSP DAC CONNETIONS
/*
	SPI conection to MCP4921 12bit dac
	PIN 	NAME			CONNECT TO  
	1			VDD				3.3v
	2			/CS				spi cs
	3			SCK				spi sck
	4			SDI				spi sdo
	5			/LDAC			10k resistor to gnd
	6			VREFA			vref (2.5v)
	7			AVSS			gnd
	8			VOUTA			output 
*/

#define DAC_CONF	(0x3<<12) 

void delay_ms(int delay_time);

unsigned short dac_val=0x8FF;
int main(){
	spi_init();
	while(1){
		spi_output16((DAC_CONF|(dac_val)));
		delay_ms(0xFFFF);
	}
	//return 0;
}

void delay_ms(int delay_time){
	for(int i=0; i<delay_time; i++){
	}
}
