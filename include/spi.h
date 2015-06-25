#ifndef _SPI_H
#define _SPI_H
#include "stm32f4xx.h"                  // Device header
/**
	PA4 - SPI1_NSS/CS
	PA5 - SPI1_SCK
	PA6 - SPI1_MISO
	PA7 - SPI1_MOSI
*/
void spi_init(void);
void spi_output16(unsigned short spi_data);
#endif
