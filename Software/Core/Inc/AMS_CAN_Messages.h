/*
 * AMS_CAN_Messages.h
 *
 *  Created on: Sep 30, 2020
 *      Author: Thomas Fraser
 */

#ifndef INC_AMS_CAN_MESSAGES_H_
#define INC_AMS_CAN_MESSAGES_H_

#include "stdbool.h"
#include "main.h"

#define HEARTBEAT_RESPONSE_ID 0x8404001
#define CELL_VOLTAGE_SHUTDOWN_ID 0x400000
#define CELL_TEMPERATURE_SHUTDOWN_ID 0x400001
#define START_UP_ID 0x10408000
#define RESET_TRACTIVE_ID 0x10408001
#define SHUTDOWN_ID 0x10408002
#define REQUEST_TEMPERATURE_ID 0x10408003
#define TRANSMIT_TEMPERATURE_ID 0x1040C003
#define REQUEST_CHARGE_STATE_ID 0x10408004
#define TRANSMIT_CHARGE_STATE_ID 0x1040C004
#define READY_ID 0x1040C000
#define BMS_TRANSMIT_DEVICE_ID_ID 0x1048C000
#define HEARTBEAT_REQUEST_ID 0x00 // TODO FIX

typedef struct
{
	uint32_t extID;
	uint8_t data[2];
} AMS_CellVoltageShutdown_t;
// Should the voltage be a .1f?
AMS_CellVoltageShutdown_t AMS_Compose_CellVoltageShutdown(uint8_t cellNum, uint8_t bmsID, uint8_t voltage);
// Should the voltage be a .1f?
void AMS_Parse_CellVoltageShutdown(AMS_CellVoltageShutdown_t packet, uint8_t* cellNum, uint8_t* bmsID, uint8_t* voltage);

typedef struct
{
	uint32_t extID;
	uint8_t data[2];
} AMS_CellTemperatureShutdown_t;
// Should temperature be a .1f?
AMS_CellTemperatureShutdown_t AMS_Compose_CellTemperatureShutdown(uint8_t cellNum, uint8_t bmsID, uint8_t temperature);
// Should temperature be a .1f?
void AMS_Parse_CellTemperatureShutdown(AMS_CellTemperatureShutdown_t packet, uint8_t* cellNum, uint8_t* bmsID, uint8_t* temperature);

typedef struct
{
	uint32_t extID;
	uint8_t data[2];
} AMS_MissingBMS_t;
AMS_MissingBMS_t AMS_Compose_MissingBMS(uint8_t data[12])
{
	//TODO
}
void AMS_Parse_MissingBMS(uint8_t* data[12])
{
	//TODO
}

typedef struct
{
	uint32_t extID;
} AMS_HeartbeatRequest_t;
AMS_HeartbeatRequest_t AMS_Compose_HeartbeatRequest()
{
	AMS_HeartbeatRequest_t p;
	p.extID = HEARTBEAT_REQUEST_ID;

	return p;
}

typedef struct
{
	uint32_t extID;
	uint8_t data[4];
} AMS_HeartbeatResponse_t;
AMS_HeartbeatResponse_t AMS_Compose_HeartbeatResponse(bool HVAn, bool HVBn, bool precharge, bool HVAp, bool HVBp, uint8_t averageVoltage, uint16_t runtime);
void AMS_Parse_HeartbeatResponse(AMS_HeartbeatResponse_t packet, bool* HVAn, bool* HVBn, bool* precharge, bool* HVAp, bool* HVBp, uint8_t* averageVoltage, uint16_t* runtime);

typedef struct
{
	uint32_t extID;
} AMS_StartUp_t;
AMS_StartUp_t AMS_Compose_StartUp();

typedef struct
{
	uint32_t extID;
} AMS_ResetTractive_t;
AMS_ResetTractive_t AMS_Compose_ResetTractive();

typedef struct
{
	uint32_t extID;
} AMS_Shutdown_t;
AMS_Shutdown_t AMS_Compose_Shutdown();

typedef struct
{
	uint32_t extID;
} AMS_RequestTemperature_t;
AMS_RequestTemperature_t AMS_Compose_RequestTemperature();

typedef struct
{
	uint32_t extID;
	uint8_t data[1];
} AMS_TransmitTemperature_t;
AMS_TransmitTemperature_t AMS_Compose_TransmitTemperature(uint8_t temperature);
void AMS_Parse_TransmitTemperature(AMS_TransmitTemperature_t packet, uint8_t* temperature);

typedef struct
{
	uint32_t extID;
} AMS_RequestChargeState_t;
AMS_RequestChargeState_t AMS_Compose_RequestChargeState();

typedef struct
{
	uint32_t extID;
	uint8_t data[2];
} AMS_TransmitChargeState_t;
AMS_TransmitChargeState_t AMS_Compose_TransmitChargeState(uint16_t chargeState);
void AMS_Parse_TransmitChargeState(AMS_TransmitChargeState_t packet, uint16_t* chargeState);

typedef struct
{
	uint32_t extID;
} AMS_Ready_t;
AMS_Ready_t AMS_Construct_Ready();

typedef struct // Spec could change for this packet.
{
	uint32_t extID;
	uint8_t data[4];
} BMS_TransmitDeviceID_t;
BMS_TransmitDeviceID_t BMS_Compose_TransmitDeviceID(uint32_t deviceID);
void BMS_Parse_TransmitDeviceID(BMS_TransmitDeviceID_t packet, uint32_t* deviceID);

#endif /* INC_AMS_CAN_MESSAGES_H_ */
