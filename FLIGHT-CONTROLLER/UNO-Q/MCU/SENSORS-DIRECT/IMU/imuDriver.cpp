/*
WHAT:
  Driver for the IMU wired directly to the Uno Q MCU.

WHY:
  Attitude comes from the IMU. It sits on the flight MCU so the control
  loop does not wait for Pico 1, Pico 2, the MPU, or the Pi 5.

HOW:
  setupImu() will start the IMU bus and chip. readImuSample() will later
  return real accel and gyro values. Right now it returns zeros.

IMPORTANT:
  This is a starter skeleton only. Zero is not a real attitude. Never arm
  motors from zero IMU data. Do not trust IMU samples from the Pi, phone,
  or web app.
*/

struct ImuSample {
  float accelX = 0.0f;
  float accelY = 0.0f;
  float accelZ = 0.0f;
  float gyroX = 0.0f;
  float gyroY = 0.0f;
  float gyroZ = 0.0f;
  bool isValid = false;
};

void setupImu() {
  // Later: IMU chip identity, bus speed, and range.
}

ImuSample readImuSample() {
  // isValid stays false until a real chip answers.
  ImuSample imuSample;
  imuSample.isValid = false;
  return imuSample;
}
