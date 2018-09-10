/*
 * SPI_Master.h
 *
 * Created: 3/19/2018 3:47:50 AM
 *  Author: mahmo
 */ 


#ifndef SPI -MASTER_H_
#define SPI -MASTER_H_
#define F_CPU 8000000ul
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define SS 4		// Slave Select        is Bit No.4
#define MOSI 5 		// Master Out Slave In is Bit No.5
#define MISO 6		// Master In Slave Out is Bit No.6
#define SCK 7 		// Shift Clock         is Bit No.7

void Spi_Initialization_Master (void);

uint8_t Spi_Tranceiver_8bit(uint8_t data);

// uint16_t Spi_Tranceiver_16bit(uint16_t data);
// 
// void spi_Burst_Transit(uint16_t data);



#endif /* SPI-MASTER_H_ */