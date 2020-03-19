#ifndef	_AMS_TEST_H
#define	_AMS_TEST_H
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "libs/macros.h"
#include "libs/usb_transmit.h"

/// Relay contol pins
#define DDR_RELAY					DDRF
#define RELAY_PORT					PORTF
#define RELAY_CONTROL_PRECHARGE		PORTF7
#define RELAY_CONTROL_NEGATIVE		PORTF6
#define RELAY_CONTROL_POSITIVE		PORTF5

/// Fault pins
#define DDR_FAULT           DDRB
#define FAULT_REG			PINB
#define BMS_FAULT_PIN       PINB1
#define SHUTDOWN_PIN        PINB2

/// Ready to drive pin
#define DDR_RTD				DDRB
#define RTD_REG				PINB
#define RTD_PIN				PINB3


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