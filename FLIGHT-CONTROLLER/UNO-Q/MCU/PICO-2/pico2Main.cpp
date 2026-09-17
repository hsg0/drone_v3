/*
WHAT:
  Main program for Pico 2, a second sensor coprocessor next to the Uno Q MCU.

WHY:
  Pico 2 owns a different sensor group from Pico 1 so one Pico failing or
  blocking does not stop the other set of sensors.

HOW:
  setupPico2() prepares the board, then runPico2Loop() reads Pico 2 sensors
  and will later send a packet to the Uno Q MCU.

IMPORTANT:
  This is a starter skeleton only. Pico 2 must never command motors.
  It only gathers sensor values and reports them.
*/

#include <cstdint>

// ---------------------------------------------------------------------------
// Sensor packet
// ---------------------------------------------------------------------------

struct Pico2SensorPacket {
  std::uint32_t sampleCount = 0;
};

Pico2SensorPacket readPico2Sensors() {
  // Later: call the real Pico 2 sensor drivers in PICO-2-SENSORS.
  return Pico2SensorPacket();
}

void sendPico2PacketToFlightMcu(const Pico2SensorPacket& pico2SensorPacket) {
  // Later: UART / SPI / I2C to the Uno Q MCU.
  (void)pico2SensorPacket;
}

// ---------------------------------------------------------------------------
// Pico 2 loop
// ---------------------------------------------------------------------------

void setupPico2() {
  // Later: clocks, sensor buses, link to the flight MCU.
}

void runPico2Loop() {
  Pico2SensorPacket pico2SensorPacket = readPico2Sensors();
  sendPico2PacketToFlightMcu(pico2SensorPacket);
}

int main() {
  setupPico2();

  while (true) {
    runPico2Loop();
  }
}
