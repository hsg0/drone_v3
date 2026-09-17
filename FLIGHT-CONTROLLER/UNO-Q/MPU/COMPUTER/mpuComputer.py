"""
WHAT:
  Python program for the Uno Q Linux microprocessor (MPU).

WHY:
  The MPU is the small Linux computer on the flight controller. It can log,
  inspect, and pass messages. It must not replace the MCU flight loop.

HOW:
  startMpuComputer() runs a simple loop. Later this process will talk to
  the MCU and to the Pi 5 brain. Right now it only prints that it is waiting.

IMPORTANT:
  This is a starter skeleton only. No packages are installed. The MPU must
  never arm motors or decide that it is safe to fly. Those decisions stay
  on the MCU.
"""

import time


def startMpuComputer():
    print("MPU computer started. Waiting for MCU link.")

    while True:
        # Later: read MCU telemetry, then send it to the Pi 5.
        time.sleep(1)


if __name__ == "__main__":
    startMpuComputer()
