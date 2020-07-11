#include "AMS.h"

uint8_t sdFault = 0;
uint8_t bmsFault = 0;
uint8_t rtd = 0;

uint8_t counter = 1;
uint8_t readCounter = 0;

char buf[48];


void board_init(void) {
    // Set Relay control pins as outputs to control triggers
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_PRECHARGE);
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_NEGATIVE);
    SET_OUTPUT(DDR_RELAY, RELAY_CONTROL_POSITIVE);

    // Use pins to inform about failure from each side
    SET_INPUT(DDR_FAULT, BMS_FAULT_PIN);
    SET_INPUT(DDR_FAULT, SHUTDOWN_PIN);

    SET_INPUT(DDR_RTD, RTD_PIN);

    // Set LOW to disable relay triggers
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_PRECHARGE, LOW);
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_NEGATIVE, LOW);
    WRITE_BIT(RELAY_PORT, RELAY_CONTROL_POSITIVE, LOW);

    //TODO: Copy a code from AMS_V3 to trigger Relays at particular order initially.
}

void board_routine(void) {
    // if we're not ready to drive yet check if we are else do nothing
    if (!rtd) {
        //if (BIT_IS_SET(RTD_REG, RTD_PIN)) {
        rtd = 1;

        // turn on precharge and negative contactor
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_PRECHARGE, HIGH);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_NEGATIVE, HIGH);
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_POSITIVE, LOW);

        // wait 0.5 seconds
        _delay_ms(1500);

        // turn on positive contactor
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_POSITIVE, HIGH);

        _delay_ms(500);

        // turn off precharge
        WRITE_BIT(RELAY_PORT, RELAY_CONTROL_PRECHARGE, LOW);


        // }
    }

    /*

    // checking for faults
    if (!sdFault && !bmsFault) {
        // if shutdown is low turn off both contactors and set variable
        if (!BIT_IS_SET(FAULT_REG, SHUTDOWN_PIN)) {
            sdFault = 1;
        }

        // if bms fault is high turn off both contactors and set variable
        if (BIT_IS_SET(FAULT_REG, BMS_FAULT_PIN)) {
            bmsFault = 1;
        }

        if (bmsFault || sdFault) {
            // we've got a fault of some sort so shut everything off

            WRITE_BIT(RELAY_PORT, RELAY_CONTROL_PRECHARGE, LOW);
            WRITE_BIT(RELAY_PORT, RELAY_CONTROL_NEGATIVE, LOW);
            WRITE_BIT(RELAY_PORT, RELAY_CONTROL_POSITIVE, LOW);

        }


    } else {
        // we've encountered a fault so stop stop stop stop
    }

    */
}


/* Contactors and Precharge */
#define SHDN_NEG_ON		WRITE_BIT(RELAY_PORT, RELAY_CONTROL_NEGATIVE, LOW)
#define SHDN_NEG_OFF	WRITE_BIT(RELAY_PORT, RELAY_CONTROL_NEGATIVE, HIGH)
#define PRE_CHARGE_ON	WRITE_BIT(RELAY_PORT, RELAY_CONTROL_PRECHARGE, LOW)
#define PRE_CHARGE_OFF	WRITE_BIT(RELAY_PORT, RELAY_CONTROL_PRECHARGE, HIGH)
#define SHDN_POS_ON		WRITE_BIT(RELAY_PORT, RELAY_CONTROL_POSITIVE, LOW)
#define SHDN_POS_OFF	WRITE_BIT(RELAY_PORT, RELAY_CONTROL_POSITIVE, HIGH)

uint8_t precharge = 1;
uint8_t positive_on = 0;

void old_AMS_board(void) {
    if(bmsFault == 0 && sdFault == 0) { // Use PDM CAN packet
        if(precharge) { // Shutdown -
            PRE_CHARGE_ON;
            SHDN_NEG_ON;
            positive_on = 1;
            precharge = 0;
            _delay_ms(100);
        } else {
            PRE_CHARGE_OFF;
        }

        if(positive_on) { // Shutdown +
            SHDN_POS_ON;
        } else {
            SHDN_POS_OFF;
        }
    } else {
        positive_on = 0;
        precharge = 0;
        PRE_CHARGE_OFF;
        SHDN_POS_OFF;
    }
}