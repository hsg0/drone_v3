/*
WHAT:
  Main program for Pico 1, a sensor coprocessor next to the Uno Q MCU.

WHY:
  Pico 1 owns one sensor group so the flight MCU is not blocked collecting
  slower or bulkier sensor data.

HOW:
  setupPico1() prepares the board, then runPico1Loop() reads Pico 1 sensors
  and will later send a packet to the Uno Q MCU.

IMPORTANT:
  This is a starter skeleton only. Pico 1 must never command motors.
  It only gathers sensor values and reports them.
*/

#include <cstdint>

// ---------------------------------------------------------------------------
// Sensor packet
// ---------------------------------------------------------------------------

struct Pico1SensorPacket {
  std::uint32_t sampleCount = 0;
};

Pico1SensorPacket readPico1Sensors() {
  // Later: call the real Pico 1 sensor drivers in PICO-1-SENSORS.
  return Pico1SensorPacket();
}

void sendPico1PacketToFlightMcu(const Pico1SensorPacket& pico1SensorPacket) {
  // Later: UART / SPI / I2C to the Uno Q MCU.
  (void)pico1SensorPacket;
}

// ---------------------------------------------------------------------------
// Pico 1 loop
// ---------------------------------------------------------------------------

void setupPico1() {
  // Later: clocks, sensor buses, link to the flight MCU.
}

void runPico1Loop() {
  Pico1SensorPacket pico1SensorPacket = readPico1Sensors();
  sendPico1PacketToFlightMcu(pico1SensorPacket);
}

int main() {
  setupPico1();

  while (true) {
    runPico1Loop();
  }
}
