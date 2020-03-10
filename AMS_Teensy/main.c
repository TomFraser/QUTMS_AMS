#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>
#include "libs/cpu_speed.h"
#include "libs/usb_serial.h"
#include "libs/macros.h"
#include "libs/usb_transmit.h"

#include "AMS.h"

void control_usb_init(void);

#define INPUT1_REG DDRF
#define INPUT2_REG DDRB

#define INPUT_1 PINF7
#define INPUT_2 PINB4

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

    SET_INPUT(INPUT1_REG, INPUT_1);
    SET_INPUT(INPUT2_REG, INPUT_2);

    _delay_ms(100);

    set_relay1(LOW);
    set_relay2(LOW);
    set_relay3(LOW);
    set_relay4(LOW);

    /*Forever loop*/
    while(1) {
        // if we're reading something on this input turn the relay on
        if (BIT_VALUE(PINF, INPUT_1)) {
            set_relay1(HIGH);
        } else { // turn it off
            set_relay1(LOW);
        }

        // if we're reading something on this input turn the relay on
        if (BIT_VALUE(PINB, INPUT_2)) {
            set_relay2(HIGH);
        } else { // turn it off
            set_relay2(LOW);
        }

        _delay_ms(100);
    }
}

void control_usb_init(void) {
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