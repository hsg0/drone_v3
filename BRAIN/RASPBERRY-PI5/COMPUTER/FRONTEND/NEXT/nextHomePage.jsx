/**
 * WHAT:
 *   Starter Next.js page for the web / ground-station UI.
 *
 * WHY:
 *   The web app is the other way a person talks to the Pi 5 brain. It stays
 *   in this folder so it does not mix with Expo.
 *
 * HOW:
 *   One page shows that the ground station is a starter and is not connected
 *   yet. Later this page will call the Node backend. Do not install Next
 *   packages yet; this file only saves the folder and the intended shape.
 *
 * IMPORTANT:
 *   This is a starter skeleton only. It will not run until Next.js is
 *   installed later. The browser must never be trusted to fly the drone.
 */

export default function NextHomePage() {
  return (
    <main>
      <h1>Drone ground station</h1>
      <p>Starter page. Not connected to the Pi 5 backend yet.</p>
    </main>
  );
}
