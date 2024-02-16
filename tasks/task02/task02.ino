#include <TaskManagerIO.h>

TaskManager taskManager;

void togglePin3() {
  static bool pinState = LOW;
  pinState = !pinState;
  digitalWrite(3, pinState);
  taskManager.scheduleOnce(5, togglePin3, TIME_SECONDS);
}

void togglePin5() {
  static bool pinState = LOW;
  pinState = !pinState;
  digitalWrite(5, pinState);
  taskManager.scheduleOnce(500, togglePin5, TIME_MILLIS);
}

void togglePin6() {
  static bool pinState = LOW;
  pinState = !pinState;
  digitalWrite(6, pinState);
  taskManager.scheduleOnce(250, togglePin6, TIME_MILLIS);
}

void togglePin9() {
  static bool pinState = LOW;
  pinState = !pinState;
  digitalWrite(9, pinState);
  taskManager.scheduleOnce(50, togglePin9, TIME_MILLIS);
}

void togglePin10() {
  static bool pinState = LOW;
  pinState = !pinState;
  digitalWrite(10, pinState);
  taskManager.scheduleOnce(25, togglePin10, TIME_MILLIS);
}

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  togglePin3();
  togglePin5();
  togglePin6();
  togglePin9();
  togglePin10();
}

void loop() {
  taskManager.runLoop();
}