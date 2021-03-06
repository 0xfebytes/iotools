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

/*-----------------------------------------------------------------------------
 *  _set_bit and _clear_bit are macros defined in header file
 *-----------------------------------------------------------------------------*/

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_init
 *  Description:  sets up discrete io
 * =====================================================================================
 */
void disc_init ( IO *io, IO_DIR dir )
{
		if ( dir ) {
				_set_bit(*io->_ddr, io->_channel);
		}
		else {
				_clear_bit(*io->_ddr, io->_channel);
		}
}		/* -----  end of function disc_init  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_on
 *  Description:  turns io on (does not change direction)
 * =====================================================================================
 */
void disc_on ( IO *io )
{
		_set_bit(*io->_port, io->_channel);
}		/* -----  end of function disc_on  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_off
 *  Description:  turns io off (does not change direction)
 * =====================================================================================
 */
void disc_off ( IO *io )
{
		_clear_bit(*io->_port, io->_channel);
}		/* -----  end of function disc_off  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_read
 *  Description:  reads the state of io
 * =====================================================================================
 */
uint8_t disc_read ( IO *io )
{
		return *io->_pin & ( 1<<io->_channel );
}		/* -----  end of function disc_read  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  disc_toggle
 *  Description:  
 * =====================================================================================
 */
void disc_toggle ( IO *io, uint16_t time, TIME_UNIT unit )
{
		// TIME_UNIT ms=0, sec=1; convert sec to ms
		if( unit ) {
				time *= 1000;
		}

		disc_on(io);
		_delay_ms(time);
		disc_off(io);
		_delay_ms(time);
}		/* -----  end of function disc_toggle  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  io_new
 *  Description:  create new io object
 * =====================================================================================
 */
IO *io_new ( volatile uint8_t *port, volatile uint8_t *pin,
				volatile uint8_t *ddr, uint8_t channel )
{
		IO *io = malloc(sizeof(IO));

		io->_port = port;
		io->_pin = pin;
		io->_ddr = ddr;
		io->_channel = channel;

		return io;
}		/* -----  end of function io_new  ----- */
