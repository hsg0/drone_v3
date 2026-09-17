/*
WHAT:
  Main real-time flight program for the Uno Q microcontroller.

WHY:
  Flying must happen here, not on the Pi 5. This file is the MCU entry
  point so attitude control stays on the real-time chip.

HOW:
  setupFlightController() prepares the board, then runFlightLoop() repeats:
  read sensors, decide motor output, send motor output. Until hardware is
  wired, motors stay off.

IMPORTANT:
  This is a starter skeleton only. It is not flight-ready. Motors must stay
  off until real IMU data and real control code exist. Do not arm motors
  from Python, Node, or the phone.
*/

#include <cstdint>

// ---------------------------------------------------------------------------
// Motor safety
// ---------------------------------------------------------------------------

struct MotorOutput {
  std::uint16_t frontRight = 0;
  std::uint16_t rearRight = 0;
  std::uint16_t rearLeft = 0;
  std::uint16_t frontLeft = 0;
};

MotorOutput stoppedMotors() {
  // Zero means "do not spin". This is the only safe output until control
  // is proven with a real IMU.
  return MotorOutput();
}

// ---------------------------------------------------------------------------
// Flight loop
// ---------------------------------------------------------------------------

void setupFlightController() {
  // Later: clocks, IMU bus, motor outputs, failsafe pin.
}

void runFlightLoop() {
  // Later: read IMU from SENSORS-DIRECT/IMU, then compute control.
  MotorOutput motorOutput = stoppedMotors();
  (void)motorOutput;
}

int main() {
  setupFlightController();

  while (true) {
    runFlightLoop();
  }
}
