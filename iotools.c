/*
 * =====================================================================================
 *
 *       Filename:  iotools.c
 *
 *    Description:  class based io control
 *
 *        Version:  1.0
 *        Created:  01/26/2015 03:30:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tim Ryan (TJR), tim.ryan3131@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdint.h>
#include <util/delay.h>
#include "iotools.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_init
 *  Description:  sets up discrete io
 * =====================================================================================
 */
void disc_init ( IO *io, IO_DIR dir )
{
		if ( dir ) {
				*io->_ddr |= ( 1<<io->_channel );
		}
		else {
				*in->_ddr &= ~( 1<<io->_channel );
		}

		return NULL
}		/* -----  end of function disc_init  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_on
 *  Description:  turns io on (does not change direction)
 * =====================================================================================
 */
void disc_on ( IO *io )
{
		*io->_port |= ( 1<<io->_channel );

		return NULL;
}		/* -----  end of function disc_on  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_off
 *  Description:  turns io off (does not change direction)
 * =====================================================================================
 */
void disc_off ( IO *io )
{
		*io->_port &= ~( 1<<io->_channel );

		return NULL;
}		/* -----  end of function disc_off  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_read
 *  Description:  reads the state of io
 * =====================================================================================
 */
void disc_read ( IO *io )
{
		return *io->_pin & ( 1<<io->_channel );
}		/* -----  end of function disc_read  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  io_new
 *  Description:  create new io object
 * =====================================================================================
 */
void io_new ( volatile uint8_t *port, volatile uint8_t *pin,
				volatile uint8_t *ddr, uint8_t channel )
{
		io->_port = port;
		io->_pin = pin;
		io->_ddr = ddr;
		io->_channel = channel;

		return NULL;
}		/* -----  end of function io_new  ----- */
