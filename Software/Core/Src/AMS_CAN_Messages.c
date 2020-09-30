/*
 * AMS_CAN_Messages.c
 *
 *  Created on: 30 Sep 2020
 *      Author: Tom
 */


#include "AMS_CAN_Messages.h"

/* Cell Voltage Shutdown */
AMS_CellVoltageShutdown_t AMS_Compose_CellVoltageShutdown(uint8_t cellNum, uint8_t bmsID, uint8_t voltage)
{
	AMS_CellVoltageShutdown_t p;
	p.extID = CELL_VOLTAGE_SHUTDOWN_ID;
	p.data[0] = (cellNum & 0xF) << 4 | (bmsID & 0xF);
	p.data[1] = (voltage & 0xFF);

	return p;
}

void AMS_Parse_CellVoltageShutdown(AMS_CellVoltageShutdown_t packet, uint8_t* cellNum, uint8_t* bmsID, uint8_t* voltage)
{
	*cellNum = (uint8_t)(packet.data[0] >> 4);
	*bmsID = (uint8_t)(packet.data[0] & 0xF);
	*voltage = (uint8_t)(packet.data[1] & 0xFF);
}

/* Cell Temperature Shutdown */
AMS_CellTemperatureShutdown_t AMS_Compose_CellTemperatureShutdown(uint8_t cellNum, uint8_t bmsID, uint8_t temperature)
{
	AMS_CellTemperatureShutdown_t p;
	p.extID = CELL_TEMPERATURE_SHUTDOWN_ID;
	p.data[0] = (cellNum & 0xF) << 4 | (bmsID & 0xF);
	p.data[1] = (temperature & 0xFF);

	return p;
}

void AMS_Parse_CellTemperatureShutdown(AMS_CellTemperatureShutdown_t packet, uint8_t* cellNum, uint8_t* bmsID, uint8_t* temperature)
{
	*cellNum = (uint8_t)(packet.data[0] >> 4);
	*bmsID = (uint8_t)(packet.data[0] & 0xF);
	*temperature = (uint8_t)(packet.data[1] & 0xFF);
}

AMS_MissingBMS_t AMS_Compose_MissingBMS(uint8_t data[12])
{
	//TODO
	AMS_MissingBMS_t p;
	p.extID = MISSING_BMS_ID;

	return p;
}

void AMS_Parse_MissingBMS(uint8_t* data[12])
{
	//TODO
}

AMS_HeartbeatRequest_t AMS_Compose_HeartbeatRequest()
{
	AMS_HeartbeatRequest_t p;
	p.extID = HEARTBEAT_REQUEST_ID;

	return p;
}

/* Heartbeat Response */
AMS_HeartbeatResponse_t AMS_Compose_HeartbeatResponse(bool HVAn, bool HVBn, bool precharge, bool HVAp, bool HVBp, uint8_t averageVoltage, uint16_t runtime)
{
	AMS_HeartbeatResponse_t p;
	p.extID = HEARTBEAT_RESPONSE_ID;

	p.data[0] = HVAn | (HVBn << 1) | (precharge << 2) | (HVAp << 4) | (HVBp << 5);
	p.data[1] = averageVoltage;
	p.data[2] = (runtime & 0xFF);
	p.data[3] = (runtime >> 8);

	return p;
}

void AMS_Parse_HeartbeatResponse(AMS_HeartbeatResponse_t packet, bool* HVAn, bool* HVBn, bool* precharge, bool* HVAp, bool* HVBp, uint8_t* averageVoltage, uint16_t* runtime)
{
	*HVAn = (bool)(packet.data[0] & 0x1);
	*HVBn = (bool)(packet.data[0] & 0x2);
	*precharge = (bool)(packet.data[0] & 0x4);

	*HVAp = (bool)(packet.data[0] & 0x10);
	*HVBp = (bool)(packet.data[0] & 0x20);

	*averageVoltage = (uint8_t)(packet.data[1]);
	*runtime = (uint16_t)(packet.data[3] << 8 | packet.data[2]);
}

/* Start Up */
AMS_StartUp_t AMS_Compose_StartUp()
{
	AMS_StartUp_t p;
	p.extID = START_UP_ID;

	return p;
}

/* Reset Tractive */
AMS_ResetTractive_t AMS_Compose_ResetTractive()
{
	AMS_ResetTractive_t p;
	p.extID = RESET_TRACTIVE_ID;

	return p;
}

/* Shutdown */
AMS_Shutdown_t AMS_Compose_Shutdown()
{
	AMS_Shutdown_t p;
	p.extID = SHUTDOWN_ID;

	return p;
}

/* Request Temperature */
AMS_RequestTemperature_t AMS_Compose_RequestTemperature()
{
	AMS_RequestTemperature_t p;
	p.extID = REQUEST_TEMPERATURE_ID;

	return p;
}

/* Transmit Temperature */
AMS_TransmitTemperature_t AMS_Compose_TransmitTemperature(uint8_t temperature)
{
	AMS_TransmitTemperature_t p;
	p.extID = TRANSMIT_TEMPERATURE_ID;
	p.data[0] = temperature;

	return p;
}

void AMS_Parse_TransmitTemperature(AMS_TransmitTemperature_t packet, uint8_t* temperature)
{
	*temperature = packet.data[0];
}

/* Request Charge State */
AMS_RequestChargeState_t AMS_Compose_RequestChargeState()
{
	AMS_RequestChargeState_t p;
	p.extID = REQUEST_CHARGE_STATE_ID;

	return p;
}

/* Transmit Charge State */
AMS_TransmitChargeState_t AMS_Compose_TransmitChargeState(uint16_t chargeState)
{
	AMS_TransmitChargeState_t p;
	p.extID = TRANSMIT_CHARGE_STATE_ID;
	p.data[0] = chargeState >> 8;
	p.data[1] = (chargeState & 0xFF);

	return p;
}

void AMS_Parse_TransmitChargeState(AMS_TransmitChargeState_t packet, uint16_t* chargeState)
{
	*chargeState = (packet.data[0] << 8 | packet.data[1]);
}

/* Ready */
AMS_Ready_t AMS_Construct_Ready()
{
	AMS_Ready_t p;
	p.extID = READY_ID;

	return p;
}
/* Transmit Device ID */
BMS_TransmitDeviceID_t BMS_Compose_TransmitDeviceID(uint32_t deviceID)
{
	BMS_TransmitDeviceID_t p;
	p.extID = BMS_TRANSMIT_DEVICE_ID_ID;
	p.data[0] = (deviceID & 0xFF);
	p.data[1] = (deviceID >> 8) & 0xFF;
	p.data[2] = (deviceID >> 16) & 0xFF;
	p.data[3] = (deviceID >> 24) & 0xFF;

	return p;
}

void BMS_Parse_TransmitDeviceID(BMS_TransmitDeviceID_t packet, uint32_t* deviceID)
{
	*deviceID = (packet.data[3] << 24 | packet.data[2] << 16 | packet.data[1] << 8 | packet.data[0]);
}

