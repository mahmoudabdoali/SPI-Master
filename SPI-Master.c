/*
 * SPI_Master.c
 *
 * Created: 3/19/2018 3:50:43 AM
 *  Author: mahmo
 */ 

#include "SPI-Master.h"


void Spi_Initialization_Master (void)
{
	DDRB |= (1<<MOSI) | (1<<SCK) | (1<<SS) ;
	DDRB &= ~(1<<MISO);
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);			//Enable SPI, Set as Master
	SPSR |= (1<<SPI2X);								//set sck=1MHZ
}


uint8_t Spi_Tranceiver_8bit(uint8_t data)
{
	SPDR = data;									//Load data into the buffer
	while((SPSR) & (1<<SPIF)==0 );					//Wait until transmission complete
	return(SPDR);									//Return received data
}



// uint16_t Spi_Tranceiver_16bit(uint16_t data)
// {
// 	part_1=data;
// 	Spi_Tranceiver_8bit(part_1);
//	 
// 	part_2=(data>>8);
// 	Spi_Tranceiver_8bit(part_2);
// 	
// 	full_data=((part_2<<8)|part_1);
// 	Send_An_Integer_WithLoc(1,1,full_data,3);
// 	
// 	return full_data;
// 	
// }


// void spi_Burst_Transit(uint16_t data)
// {
// 		PORTB&=~(1U<<SS);

// 		SPDR = data;									
// 		while((SPSR) & (1<<SPIF)==0 );
// 		
// 		SPDR= data>>8;
// 		while((SPSR) & (1<<SPIF)==0 );

// 		PORTB|=(1U<<SS);
// }