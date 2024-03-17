#include <TaskManagerIO.h>

TaskManager myTaskManager;

int states[5] = {LOW};
const long intervals[5] = {10000, 1000, 500, 100, 50};
const int pins[5] = {3, 5, 6, 9, 10};

void togglePin(int index) {
  states[index] ^= HIGH;

  digitalWrite(pins[index], states[index]);
}

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pins[i], OUTPUT);

    myTaskManager.scheduleFixedRate(intervals[i], [i] {
      togglePin(i);
    }, TIME_MICROS);
  }
}

void loop() {
  myTaskManager.runLoop();
}