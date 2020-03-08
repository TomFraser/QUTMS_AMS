#include "AMS_Test.h"

uint8_t sdFault = 0;
uint8_t bmsFault = 0;

uint8_t counter = 1;
uint8_t readCounter = 0;

char buf[48];

void board_init(void) {
    // Set Relay control pins as outputs to control triggers
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_1);
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_2);
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_3);
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_4);

    // DDR_RELAY = (1<<RELAY_CONTROL_1)|(1<<RELAY_CONTROL_1)|
    //             (1<<RELAY_CONTROL_1)|(1<<RELAY_CONTROL_1);

    // Use pins to inform about failure from each side
    SET_INPUT(DDR_FAULT, BMS_FAULT_PIN);
    SET_INPUT(DDR_FAULT, SHUTDOWN_PIN);

    // Set HIGH to disable relay triggers
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_1, HIGH);
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_2, HIGH);
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_3, HIGH);
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_4, HIGH);

    //TODO: Copy a code from AMS_V3 to trigger Relays at particular order initially.
}

void board_routine(void) {

    // TODO: Debouncing may not be necessary in this setup

    snprintf(buf, sizeof(buf), 
        "ShutDown: ( %d ) ||| BMSFault: ( %d )\r\n", sdFault, bmsFault);
    send_buffer( buf );

    // if we're not getting anything from the shutdown line turn everything off
    if(BIT_IS_SET(FAULT_PORT, SHUTDOWN_PIN)) {
        sdFault = 1;
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_1, LOW);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_2, HIGH);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_3, HIGH);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_4, HIGH);
    }
    if(BIT_IS_SET(FAULT_PORT, BMS_FAULT_PIN))
        bmsFault = 1;

    if (readCounter < 20) {
        readCounter++;
        _delay_us(10);
        return;
    }
    
    if(bmsFault == 0 && sdFault == 0) {             // No issues
        // only run this on start up
        // but after we've checked pins are fine
        if(counter == 1) {
            _delay_ms(100);
            WRITE_BIT(RELAY_PORT, RELAY_CONTROL_4, LOW);
            _delay_ms(1000);
            WRITE_BIT(RELAY_PORT, RELAY_CONTROL_3, LOW);
            _delay_ms(100);
            counter = 0;
        }        
    } else if (bmsFault == 1 || sdFault == 1) {     // Failure
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_1, LOW);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_2, HIGH);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_3, HIGH);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_4, HIGH);
    }
}