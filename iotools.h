/*
 * =====================================================================================
 *
 *       Filename:  iotools.h
 *
 *    Description:  library for class based io control
 *
 *        Version:  1.0
 *        Created:  01/24/2015 04:01:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tim Ryan (TJR), tim.ryan3131@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _iotools_h
#define _iotools_h

// set up a few macros
#define _set_bit(REG, BIT)		(REG |= ( 1<<BIT ))
#define _clear_bit(REG, BIT)	(REG &= ~( 1<<BIT ))

enum IO_DIR {
		_IN, _OUT
};				/* ----------  end of enum IO_DIR  ---------- */
typedef enum IO_DIR IO_DIR;

enum TIME_UNIT {
		_MS, _SEC
};				/* ----------  end of enum TIME_UNIT  ---------- */
typedef enum TIME_UNIT TIME_UNIT;

struct IO {
		uint8_t *_port; // PORT
		uint8_t *_pin; // PIN
		uint8_t *_ddr; // DDR
		uint8_t *_channel;
};				/* ----------  end of struct IO  ---------- */
typedef struct IO IO;

/*-----------------------------------------------------------------------------
 *  port functions
 *-----------------------------------------------------------------------------*/
void disc_init ( IO *io, IO_DIR dir );
void disc_on ( IO *io );
void disc_off ( IO *io );
void disc_read ( IO *io );
void disc_toggle ( IO *io, uint16_t time, TIME_UNIT unit );
void io_new ( volatile uint8_t *port, volatile uint8_t *pin,
				volatile uint8_t *ddr, uint8_t channel );

#endif
