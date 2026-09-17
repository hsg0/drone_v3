/*
WHAT:
  Setup for sensors wired straight into the Uno Q MCU.

WHY:
  Some sensors are too important to wait on a Pico. This folder is for
  those direct MCU connections.

HOW:
  setupDirectSensors() will turn on the MCU buses used by direct sensors.
  The IMU itself lives in the IMU folder so this file only coordinates
  the direct-sensor group.

IMPORTANT:
  This is a starter skeleton only. Direct sensors still must not invent
  values. The IMU is the first direct sensor because attitude cannot wait.
*/

void setupDirectSensors() {
  // Later: I2C / SPI pins and clocks for sensors on the MCU.
}

void readDirectSensors() {
  // Later: call imuDriver.cpp, then any other direct MCU sensors.
}
