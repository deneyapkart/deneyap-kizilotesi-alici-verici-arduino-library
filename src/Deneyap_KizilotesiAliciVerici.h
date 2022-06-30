/*
*****************************************************************************
@file         Deneyap_KizilOtesiAliciVerici.h
@mainpage     Deneyap Infrarad Receiver Transmitter Arduino library header file
@version      v1.0.0
@date         June 29, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Infrarad Receiver Transmitter Arduino library
*****************************************************************************
*/

#ifndef __Deneyap_KizilotesiAliciVerici_H
#define __Deneyap_KizilotesiAliciVerici_H

#include <Wire.h>
#include <Arduino.h>

#define I2C_SLV_ADDR_DEFAULT (uint8_t)0x22
#define I2C_SLV_ADDR_ALT1 (uint8_t)0x56
#define I2C_SLV_ADDR_ALT2 (uint8_t)0x26
#define I2C_SLV_ADDR_ALT3 (uint8_t)0x27

#define DATA_BUFFER_SIZE 5 // in Byte (max data size)

typedef struct { // Data packet (protocol) created by master
                 // for I2C data exchange process
    uint8_t command : 3;
    uint8_t dataSize : 4;
    uint8_t data[DATA_BUFFER_SIZE];
    uint8_t rxData1;
    uint8_t rxData2;
    uint8_t rxData3;
    uint8_t rxData4;
    uint8_t interruptReady;
} Transceiver_DataPacket_TypeDef;

enum Transceiver_packetCommands { // Commands in data packet (protocol)
    READ_TRANSCEIVER = (uint8_t)0x00,
    WRITE_TRANSCEIVER,
    TRANSCEIVER_CHANGE_ADDR,
    TRANSCEIVER_REQUEST_FW_VERSION,
};

class Transceiver {
public:
    /* Check device status */
    bool begin(uint8_t address = I2C_SLV_ADDR_DEFAULT, TwoWire &port = Wire);
    bool isConnected();
    uint16_t getFwVersion();
    bool setI2Caddress(uint8_t newAddress);

    /* Functions for data manipulation */
    bool PinRead();
    uint32_t transceiverRead();
    bool transceiverWrite(uint8_t data, uint8_t address = 0x44);

private:
    TwoWire *_i2cPort;                          // Port selection (0 or 1)
    uint8_t _i2cAddress;                        // Device I2C address
    Transceiver_DataPacket_TypeDef _dataPacket; // Struct to transfer data over I2C interface

    /* I2C data transaction functions */
    uint8_t I2C_ReadData(Transceiver_DataPacket_TypeDef *dataPacket);
    uint8_t I2C_ReadData8bit(Transceiver_DataPacket_TypeDef *dataPacket);
    uint16_t I2C_ReadData16bit(Transceiver_DataPacket_TypeDef *dataPacket);
    bool I2C_SendDataPacket(Transceiver_DataPacket_TypeDef *dataPacket);
};

#endif /* __Deneyap_KizilotesiAliciVerici_H */
