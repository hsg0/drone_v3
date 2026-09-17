/*
WHAT:
  Sensor drivers that belong only to Pico 1.

WHY:
  Pico 1's sensors stay in this folder so Pico 2 and the flight MCU do not
  mix in Pico 1 hardware details.

HOW:
  Each function will talk to one Pico 1 sensor and fill one field in a
  Pico 1 sensor packet. Right now the packet is empty on purpose.

IMPORTANT:
  This is a starter skeleton only. Do not invent sensor values. Until a
  real chip is wired, return empty / zero readings.
*/

#include <cstdint>

struct Pico1SensorReading {
  std::uint32_t sampleCount = 0;
};

Pico1SensorReading readPico1SensorBoard() {
  // Later: replace this with the real Pico 1 sensor chips.
  return Pico1SensorReading();
}
