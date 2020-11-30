# DFRobot_MAX30102 Heart-rate & Oximeter Sensor Library 
DFRobot_MAX30102 MAX30102-based Heart-rate & Oximeter Sensor Library
The MAX30102 is an integrated pulse oximetry and heart-rate monitor biosensor module based on PPG ((PhotoPlethysmoGraphy).
It is so small that you can just wear it on your finger or wrist for data collecting. Internally integrated 18bit ADC, the sensor 
supports I2C data output, which could be compatible for most controllers.<br>
Examples included in this library: real-time display basic reading on serial monitor; display heartbeat on serial plotter; heart-rate and SPO2 calculation<br>
The library offers configuration methods of all registers for users to call so as to freely control MAX30102.<br>
   
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

* Heartbeat recognition and heart rate display <br>
* SPO2 Measurement <br>


## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  /*!
   *@brief Init Sensor
   *@param pWire IIC bus pointer object and construction device, can both pass or not pass parameters (Wire in default)
   *@param i2cAddr Chip IIC address (0x57 in default)
   *@return true or false
   */
  bool begin(TwoWire *pWire = &Wire, uint8_t i2cAddr = MAX30102_IIC_ADDRESS);

  /*!
   *@brief Use macro definition to configure sensor 
   *@param ledBrightness LED brightness, default value: 0x1F（6.4mA), Range: 0~255（0=Off, 255=50mA）
   *@param sampleAverage Average multiple samples then draw once, reduce data throughput, default 4 samples average
   *@param ledMode LED mode, default to use red light and IR at the same time 
   *@param sampleRate Sampling rate, default 400 samples every second 
   *@param pulseWidth Pulse width: the longer the pulse width, the wider the detection range. Default to be Max range 
   *@param adcRange ADC Measurement Range, default 4096 (nA)，15.63(pA) per LSB
   */
  void sensorConfiguration(uint8_t ledBrightness = 0x1F, uint8_t sampleAverage = SAMPLEAVG_4, \
                           uint8_t ledMode = MODE_MULTILED, uint8_t sampleRate = SAMPLERATE_400, \
                           uint8_t pulseWidth = PULSEWIDTH_411, uint8_t adcRange = ADCRANGE_4096);

  /*!
   *@brief get red value 
   *@return Red light reading
   */
  uint32_t getRed(void);

  /*!
   *@brief Get IR value 
   *@return IR reading 
   */
  uint32_t getIR(void);

  /*!
   *@brief Get module temperature in unit °C
   *@return Float temperature 
   */
  float readTemperatureC();

  /*!
   *@brief Get module temperature in unit ℉
   *@return Float temperature 
   */
  float readTemperatureF();

  /*!
   *@brief Calculate heart rate and SPO2 
   *@param *SPO2                  [out]Calculated SPO2
   *@param *SPO2Valid             [out]If the calculated SPO2 is valid, the value is 1
   *@param *heartRate             [out]Calculated heart-rate
   *@param *heartRateValid        [out]If the calculated heart-rate is valid, the value is 1
   */
  void heartrateAndOxygenSaturation(int32_t* SPO2,int8_t* SPO2Valid,int32_t* heartRate,int8_t* heartRateValid);

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
ESP8266        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 


## History

- Data 2020-6-1
- Version V0.1


## Credits

Written by(hangyu.ye@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))

