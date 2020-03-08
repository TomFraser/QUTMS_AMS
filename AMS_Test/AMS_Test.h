#ifndef	_AMS_TEST_H
#define	_AMS_TEST_H
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "macros.h"
#include "usb_transmit.h"

/// Relay contol pins
#define DDR_RELAY           DDRD
#define RELAY_PORT          PORTD
#define RELAY_CONTROL_1     PIND0
#define RELAY_CONTROL_2     PIND1
#define RELAY_CONTROL_3     PIND2
#define RELAY_CONTROL_4     PIND3

/// Fault pins
#define DDR_FAULT           DDRB
#define FAULT_PORT          PORTB
#define BMS_FAULT_PIN       PINB1
#define SHUTDOWN_PIN        PINB2


/**
 * Initialise pinout of the board
*/
void board_init(void);

/**
 * Primary routine to check status of pins and trigger relays.
*/
void board_routine(void);

/**
 * Old way of triggering relays designed by Alistair.
*/
void old_AMS_board(void);

#endif