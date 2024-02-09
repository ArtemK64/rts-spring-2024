const int pins[] = {3, 5, 6, 9, 10};
const unsigned long intervals[] = {10000, 1000, 500, 100, 50};
unsigned long previousMicros[] = {0, 0, 0, 0, 0};

bool pinStates[] = {LOW, LOW, LOW, LOW, LOW}; 

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMicros = micros();

  for (int i = 0; i < 5; i++) {
    if (currentMicros - previousMicros[i] >= intervals[i] / 2) {
      previousMicros[i] = currentMicros;

      pinStates[i] = !pinStates[i];
      digitalWrite(pins[i], pinStates[i]);
    }
  }
}