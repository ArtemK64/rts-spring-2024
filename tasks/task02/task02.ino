#include <TaskManagerIO.h>

TaskManager myTaskManager;

void togglePinDirect(uint8_t mask, uint8_t *port) {
  *port ^= mask;
}

void setup() {
  DDRD |= B00001000 | B00100000 | B01000000;
  DDRB |= B00000010 | B00000100;
  
  myTaskManager.scheduleFixedRate(10000, []() { togglePinDirect(B00001000, &PORTD); }, TIME_MICROS);
  myTaskManager.scheduleFixedRate(1000, []() { togglePinDirect(B00100000, &PORTD); }, TIME_MICROS);
  myTaskManager.scheduleFixedRate(500, []() { togglePinDirect(B01000000, &PORTD); }, TIME_MICROS);
  myTaskManager.scheduleFixedRate(100, []() { togglePinDirect(B00000010, &PORTB); }, TIME_MICROS);
  myTaskManager.scheduleFixedRate(50, []() { togglePinDirect(B00000100, &PORTB); }, TIME_MICROS);
}

void loop() {
  myTaskManager.runLoop();
}
