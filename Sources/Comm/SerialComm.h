/*	############################################################################
 * 	SerialComm.h
 *	Modulo del protocolo de comunicacion con PC a traves de RS232
 *  Created on: Feb 28, 2014
 *      Authors: Rafael Rodriguez (rafaelrs307@gmail.com)
 *				 Jorge Mendez (jorgeamendezm@gmail.com)
 * #############################################################################
 */

#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include "types.h"

#define INICIAR	0x00				//< Caracter de inicio de comunicacion.
#define FIN		0xFF				//< Caracter de fin de comunicacion.

//< Type Code. 1 byte que representa el tipo de dato a enviar.

#define PANELX			1u			//< Paneles de los sensores capacitivos.
#define PANELY			2u
#define PANELZ  		3u
#define ACCEL_ANGLE_XZ	4u			//< Angulo medido mediante el acelerometro.
#define ACCEL_ANGLE_YZ	5u
#define PIEZO			6u			//< Nivel del piezoelectrico 

//< Correction code. Posibles correcciones correspondiente a los datos enviados.

#define		NO_CORRECTION		0u
#define 	ANGLE_CORRECTION_3	1<<3
#define 	ANGLE_CORRECTION_2	1<<2
#define 	ANGLE_CORRECTION_1	1<<2
#define 	ANGLE_CORRECTION_0	1<<1

#define		TRAMA_SIZE		10u
#define 	BUF_SIZE 		64			//< Tama;o del buffer para la comunicacion
#define 	RX_LED	 		0x00		//< Mascara para LED de recepcion PTC0
#define 	TX_LED	 		0x01		//< Mascara para LED de transmision PTC1



typedef struct struct_trama{
	int8u t[TRAMA_SIZE];
	int8u tam;
}_trama;



/* ####################################################################################################################

			PROCEDIMIENTOS PARA MANEJO DEL PROTOCOLO DE COMUNICACION

 * ####################################################################################################################*/

void init_buff();			//< Necesario llamar una vez para inicializacion del buffer
void heartbit();			//< Parpadeo de led para indicar envio y recepcion de datos. Llamado en evento HEARTBIT
							//< Manejadores para la comunicacion serial.
void tx_handler();			

void send_data(_trama* data, int8u correction); //< Envia informacion a traves del puerto serial.

/*
 * 	 La PC solo envia 4 bytes. INICIO -CODE 16bits- FIN.
 * 	 Esto se usa con objetivos de sincronizacion y solicitud de informacion si asi se desea.
 */


bool read_data(_trama* data);	//< Recibe informacion del puerto serial. BLOQUEANTE.


#endif /* SERIALCOMM_H_ */
