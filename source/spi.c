#include "spi.h"
void spi_init(void){
	/*Configurar PA[7:4] como alternativo*/
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER&=~(GPIO_MODER_MODER7|GPIO_MODER_MODER6|GPIO_MODER_MODER5|GPIO_MODER_MODER4);
	GPIOA->MODER|=((0x2<<14)|(0x2<<12)|(0x2<<10)|(0x2<<8));//Usar funcion alternativa en estos pines
	GPIOA->AFR[0]=((0x5<<28)|(0x5<<24)|(0x5<<20)|(0x5<<16));
	/**/
	RCC->APB2ENR|=RCC_APB2ENR_SPI1EN;
	/*SMM = 0, SSOE= 1*/
	/*CPHA=0 CPOL=0 */
	SPI1->CR1=0;
	SPI1->CR2=0;
	
	SPI1->CR2|=SPI_CR2_SSOE;
	SPI1->CR1|=SPI_CR1_DFF|SPI_CR1_SPE|(0x6<<3)|(SPI_CR1_MSTR);//Fclk/16
}

void spi_output16(unsigned short spi_data){
	SPI1->CR1|=(SPI_CR1_SPE);
	SPI1->DR=spi_data;
	while(!(SPI1->SR&(SPI_SR_TXE)));
	while((SPI1->SR&(SPI_SR_BSY)));
	SPI1->CR1&=~(SPI_CR1_SPE);
}
