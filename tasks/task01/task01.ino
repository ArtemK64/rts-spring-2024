unsigned long previousMicros3 = 0;
unsigned long previousMicros5 = 0;
unsigned long previousMicros6 = 0;
unsigned long previousMicros9 = 0;
unsigned long previousMicros10 = 0;

bool pinState3 = LOW;
bool pinState5 = LOW;
bool pinState6 = LOW;
bool pinState9 = LOW;
bool pinState10 = LOW;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  unsigned long currentMicros = micros();

  if (currentMicros - previousMicros3 >= 10000) {
    previousMicros3 = currentMicros;
    pinState3 = !pinState3;
    digitalWrite(3, pinState3);
  }

  if (currentMicros - previousMicros5 >= 1000) {
    previousMicros5 = currentMicros;
    pinState5 = !pinState5;
    digitalWrite(5, pinState5);
  }

  if (currentMicros - previousMicros6 >= 500) {
    previousMicros6 = currentMicros;
    pinState6 = !pinState6;
    digitalWrite(6, pinState6);
  }

  if (currentMicros - previousMicros9 >= 100) {
    previousMicros9 = currentMicros;
    pinState9 = !pinState9;
    digitalWrite(9, pinState9);
  }

  if (currentMicros - previousMicros10 >= 50) {
    previousMicros10 = currentMicros;
    pinState10 = !pinState10;
    digitalWrite(10, pinState10);
  }
}