#include <Arduino.h>
#include <SerialRPC.h>
#include <RPC.h>

// put function declarations here:
#if !defined(GIGA_R1_M4) && !defined(GIGA_R1_M7)
  #error "This sketch is for the Arduino Giga R1 only."
#endif

void setup() {
  Serial.begin(115200);
  while (!Serial) continue;
  if (!SerialRPC.begin()) Serial.println("Failed to start SerialRPC");

  if (RPC.cpu_id() == CM7_CPUID) {
    Serial.println("This is the CM7 core");
  }
  else if (RPC.cpu_id() == CM4_CPUID) {
    SerialRPC.println("This is the CM4 core");
  }
}

void loop() {
  if (RPC.cpu_id() == CM7_CPUID) {
    Serial.println("CM7 Core: Loop");
  }
  else if (RPC.cpu_id() == CM4_CPUID) {
    SerialRPC.println("CM4 Core: Loop");
  }
  delay(1000);
}