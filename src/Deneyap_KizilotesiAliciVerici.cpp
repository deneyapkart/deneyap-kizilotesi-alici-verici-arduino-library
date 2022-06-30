/*
*****************************************************************************
@file         Deneyap_KizilOtesiAliciVerici.cpp
@mainpage     Deneyap Infrarad Receiver Transmitter Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.0
@date         June 29, 2022
@brief        Includes functions to controlDeneyap Infrarad Receiver Transmitter
              Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/

#include "Deneyap_KizilotesiAliciVerici.h"

/* Device Status Functions ---------------------------------------------------*/

/**
 * @brief  Configures I2C connection with user defined address and port
 * @param  address: I2C address of the device, port: I2C port number (0 or 1)
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool Transceiver::begin(uint8_t address, TwoWire &port) {
    Wire.begin();
    Wire.setClock(50000);
    _i2cAddress = address;
    _i2cPort = &port;
    _dataPacket = {0};

    return isConnected();
}

/**
 * @brief  Checks whether I2C connection established
 * @param  None
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool Transceiver::isConnected() {
    _i2cPort->beginTransmission(_i2cAddress);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}

/**
 * @brief  Requests firmware version of the device
 * @param  None
 * @retval Device firmware version
 */
uint16_t Transceiver::getFwVersion() {
    _dataPacket.command = TRANSCEIVER_REQUEST_FW_VERSION;
    _dataPacket.dataSize = 0;
    return I2C_ReadData16bit(&_dataPacket);
}

/**
 * @brief  Sets (changes) I2C address of the device
 * @param  address: I2C address to be set
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */

bool Transceiver::setI2Caddress(uint8_t newAddress) {
    _dataPacket.command = TRANSCEIVER_CHANGE_ADDR;
    _dataPacket.dataSize = 1;
    _dataPacket.data[0] = newAddress;

    bool status = I2C_SendDataPacket(&_dataPacket);

    if (status == true) {
        _i2cAddress = newAddress;
        return true;
    }
    else {
        return false;
    }
}

uint32_t Transceiver::transceiverRead() {
    uint32_t rxData;
    PinRead();
    if (_dataPacket.interruptReady == 1) {
        rxData = (uint32_t)(_dataPacket.rxData4);
        rxData |= (uint32_t)(_dataPacket.rxData3 << 8);
        rxData |= (uint32_t)(_dataPacket.rxData2 << 16);
        rxData |= (uint32_t)(_dataPacket.rxData1 << 24);
        Serial.print("0x");
        Serial.println(rxData, HEX);
    }
    else {
        rxData = 0x00;
    }

    return rxData;
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/**
 * @brief  Reads the digital pin
 * @param  None
 * @retval BitStatus : Digital pin status
 */
bool Transceiver::PinRead() {
    _dataPacket.command = (uint8_t)READ_TRANSCEIVER;
    _dataPacket.dataSize = 0;
    return I2C_ReadData(&_dataPacket);
}

/**
 * @brief  Reads the analog pin
 * @param  None
 * @retval uint16_t : Analog pin value
 */
bool Transceiver::transceiverWrite(uint8_t data, uint8_t address) {
    uint8_t addressInverse;
    uint8_t dataInverse;

    // addressInverse = address^(uint8_t)0xFF;
    dataInverse = data ^ (uint8_t)0xFF;

    _dataPacket.command = (uint8_t)WRITE_TRANSCEIVER;
    _dataPacket.dataSize = 0x04;

    _dataPacket.data[0] = 0x00; // address;
    _dataPacket.data[1] = 0xFE; // addressInverse;
    _dataPacket.data[2] = data;
    _dataPacket.data[3] = dataInverse;

    return I2C_SendDataPacket(&_dataPacket);
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
 * @brief  Reads 8bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 8bit data
 */

uint8_t Transceiver::I2C_ReadData(Transceiver_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    if (dataPacket->dataSize > 0) {
        for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
            _i2cPort->write(_dataPacket.data[i]);
    }

    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(5)) != 0); { // while(_i2cPort->available())
        dataPacket->rxData1 = _i2cPort->read();
        dataPacket->rxData2 = _i2cPort->read();
        dataPacket->rxData3 = _i2cPort->read();
        dataPacket->rxData4 = _i2cPort->read();
        dataPacket->interruptReady = _i2cPort->read();
    }
    return 1;
}

uint8_t Transceiver::I2C_ReadData8bit(Transceiver_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1)) != 0)
        return _i2cPort->read();
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t Transceiver::I2C_ReadData16bit(Transceiver_DataPacket_TypeDef *dataPacket)
{
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        uint16_t i2cData = _i2cPort->read();
        i2cData |= (_i2cPort->read() << 8);
        return i2cData;
    }
    return 0;
}

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool Transceiver::I2C_SendDataPacket(Transceiver_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
        _i2cPort->write(_dataPacket.data[i]);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}
