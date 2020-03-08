#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>
#include <cpu_speed.h>
#include <usb_serial.h>

#include "macros.h"
#include "usb_transmit.h"
#include "AMS_Test.h"

void control_usb_init(void);

/* Main Routine*/
int main(void) {
    set_clock_speed(CPU_8MHz);

    // Setting Debugging USB serial
    control_usb_init();
    send_str(PSTR(
     "\r\nAMS-teensy: USB has been initialised.\r\n"
    ));

    // Setting AMS pinout
    board_init();
    _delay_ms(100);
    while(1) {
        // Perform board routine check
        board_routine();
        _delay_ms(100);
    }
}

void control_usb_init(void){
    /* Initialise USB debugger session, waiting for terminal to connect*/
    usb_init();
    while (!usb_configured()) /* wait */ ;
	_delay_ms(1000);
    
    // wait for the user to run their terminal emulator program
    // which sets DTR to indicate it is ready to receive.
    //while (!(usb_serial_get_control() & USB_SERIAL_DTR)) /* Uncomment to wait before debugger gets initialised*/ ;

    // discard anything that was received prior.  Sometimes the
    // operating system or other software will send a modem
    // "AT command", which can still be buffered.
    usb_serial_flush_input();
}