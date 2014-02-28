/*	############################################################################
 * 	SerialComm.h
 *	Modulo del protocolo de comunicacion con PC a traves de RS232
 *  Created on: Feb 28, 2014
 *      Author: Rafael Rodriguez
 *      		Jorge Mendez
 * #############################################################################
 */

#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include "../types.h"

#define INICIAR	0x00		//< Caracter de inicio de comunicacion.
#define FIN		0xFF		//< Caracter de fin de comunicacion.

//< Type Code. 1 byte que representa el tipo de dato a enviar.

#define PANELX	1u			//< Paneles de los sensores capacitivos.
#define PANELY	2u
#define PANELZ  3u
#define ACCEL_X	4u
#define ACCEL_Y 5u
#define PIEZO	6u

//< Correction code. Posibles correcciones correspondiente a los datos enviados.

#define NO_CORRECTION	1u

#define 	BUF_SIZE 64u;		//< Tama;o del buffer para la comunicacion
#define 	RX_LED	 0x00;		//< Mascara para LED de recepcion PTC0
#define 	TX_LED	 0x01;		//< Mascara para LED de transmision PTC1

//RingBuffer para manejo de la comunicacion serial.

typedef struct struct_buffer{
	char buff[BUF_SIZE];
	int8u first;
	int8u last;	
}buffer;

/* ###########################################################################

			PROCEDIMIENTOS PARA MANEJO DEL PROTOCOLO DE COMUNICACION

 * ###########################################################################*/

void init_buff();			//< Necesario llamar una vez para inicializacion del buffer

void rx_handler();			//< Manejadores para la comunicacion serial.
void tx_handler();			

void send_data(string data); //< Envia informacion a traves del puerto serial.
void read_data(string data, int8u size);	//< Recibe informacion del puerto serial. BLOQUEANTE.

#endif /* SERIALCOMM_H_ */
