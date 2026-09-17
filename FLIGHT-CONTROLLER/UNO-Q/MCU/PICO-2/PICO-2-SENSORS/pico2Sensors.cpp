/*
WHAT:
  Sensor drivers that belong only to Pico 2.

WHY:
  Pico 2's sensors stay in this folder so Pico 1 and the flight MCU do not
  mix in Pico 2 hardware details.

HOW:
  Each function will talk to one Pico 2 sensor and fill one field in a
  Pico 2 sensor packet. Right now the packet is empty on purpose.

IMPORTANT:
  This is a starter skeleton only. Do not invent sensor values. Until a
  real chip is wired, return empty / zero readings.
*/

#include <cstdint>

struct Pico2SensorReading {
  std::uint32_t sampleCount = 0;
};

Pico2SensorReading readPico2SensorBoard() {
  // Later: replace this with the real Pico 2 sensor chips.
  return Pico2SensorReading();
}
