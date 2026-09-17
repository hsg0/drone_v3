/**
 * WHAT:
 *   Starter Expo / React Native screen for phone or tablet control.
 *
 * WHY:
 *   The mobile app is one way a person talks to the Pi 5 brain. It is not
 *   a flight controller.
 *
 * HOW:
 *   One screen shows that the app is a starter and is not connected yet.
 *   Later this app will call the Node backend. Do not install Expo packages
 *   yet; this file only saves the folder and the intended shape.
 *
 * IMPORTANT:
 *   This is a starter skeleton only. It will not run until Expo is installed
 *   later. The phone must never send motor commands around the backend and
 *   MCU safety checks.
 */

import { StyleSheet, Text, View } from "react-native";

export default function ExpoApp() {
  return (
    <View style={styles.screen}>
      <Text style={styles.title}>Drone phone app</Text>
      <Text style={styles.body}>Starter screen. Not connected to the Pi 5 backend yet.</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  screen: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
    padding: 24
  },
  title: {
    fontSize: 24,
    marginBottom: 12
  },
  body: {
    fontSize: 16,
    textAlign: "center"
  }
});
