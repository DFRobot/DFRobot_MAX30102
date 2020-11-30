/*!
 * @file heartbeatPlotter.ino
 * @brief Display heartbeat diagram on the Arduino serial plotter: click tool->"Serial Plotter". The baud rate should be 115200
 * @n Try to fix the sensor on your finger in using to avoid the effect of pressure change on data output.
 * @n This library supports mainboards: ESP8266, FireBeetle-M0, UNO, ESP32, Leonardo, Mega2560
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [YeHangYu](hangyu.ye@dfrobot.com)
 * @version  V0.1
 * @date  2020-05-29
 * @url https://github.com/DFRobot/DFRobot_MAX30102
 */

#include <DFRobot_MAX30102.h>

DFRobot_MAX30102 particleSensor;

/*
Macro definition options in sensor configuration 
sampleAverage: SAMPLEAVG_1 SAMPLEAVG_2 SAMPLEAVG_4 
               SAMPLEAVG_8 SAMPLEAVG_16 SAMPLEAVG_32
ledMode:       MODE_REDONLY  MODE_RED_IR  MODE_MULTILED
sampleRate:    PULSEWIDTH_69 PULSEWIDTH_118 PULSEWIDTH_215 PULSEWIDTH_411
pulseWidth:    SAMPLERATE_50 SAMPLERATE_100 SAMPLERATE_200 SAMPLERATE_400
               SAMPLERATE_800 SAMPLERATE_1000 SAMPLERATE_1600 SAMPLERATE_3200
adcRange:      ADCRANGE_2048 ADCRANGE_4096 ADCRANGE_8192 ADCRANGE_16384
*/
void setup()
{
  //Init serial 
  Serial.begin(115200);
  /*!
   *@brief Init sensor
   *@param pWire IIC bus pointer object and construction device, can both pass or not pass parameters (Wire in default)
   *@param i2cAddr Chip IIC address (0x57 in default)
   *@return true or false
   */
  while (!particleSensor.begin()) {
    Serial.println("MAX30102 was not found");
    delay(1000);
  }

  //Set reasonably to make sure there is clear sawtooth figure on the serial plotter
  /*!
   *@brief Use macro definition to configure sensor 
   *@param ledBrightness LED brightness, default value: 0x1F（6.4mA), Range: 0~255（0=Off, 255=50mA）
   *@param sampleAverage Average multiple samples then draw once, reduce data throughput, default 4 samples average
   *@param ledMode LED mode, default to use red light and IR at the same time
   *@param sampleRate Sampling rate, default 400 samples every second
   *@param pulseWidth Pulse width: the longer the pulse width, the wider the detection range. Default to be Max range
   *@param adcRange Measurement Range, default 4096 (nA), 15.63(pA) per LSB
   */
  particleSensor.sensorConfiguration(/*ledBrightness=*/60, /*sampleAverage=*/SAMPLEAVG_8, \
                                  /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_400, \
                                  /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

void loop()
{
  //Send raw data to serial, open seril plotter to check 
  /*!
   *@brief Get IR value 
   *@return IR reading 
   */
  Serial.println(particleSensor.getIR()); 
}
