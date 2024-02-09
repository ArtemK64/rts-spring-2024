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
  DDRD |= (1 << DDD3) | (1 << DDD5) | (1 << DDD6);
  DDRB |= (1 << DDB1) | (1 << DDB2);
}

void loop() {
  unsigned long currentMicros = micros();

  if (currentMicros - previousMicros3 >= 5000) {
    previousMicros3 = currentMicros;
    pinState3 = !pinState3;
    if (pinState3) PORTD |= (1 << PD3);
    else PORTD &= ~(1 << PD3);
  }

  if (currentMicros - previousMicros5 >= 500) {
    previousMicros5 = currentMicros;
    pinState5 = !pinState5;
    if (pinState5) PORTD |= (1 << PD5);
    else PORTD &= ~(1 << PD5);
  }

  if (currentMicros - previousMicros6 >= 250) {
    previousMicros6 = currentMicros;
    pinState6 = !pinState6;
    if (pinState6) PORTD |= (1 << PD6);
    else PORTD &= ~(1 << PD6);
  }

  if (currentMicros - previousMicros9 >= 50) {
    previousMicros9 = currentMicros;
    pinState9 = !pinState9;
    if (pinState9) PORTB |= (1 << PB1);
    else PORTB &= ~(1 << PB1);
  }

  if (currentMicros - previousMicros10 >= 25) {
    previousMicros10 = currentMicros;
    pinState10 = !pinState10;
    if (pinState10) PORTB |= (1 << PB2);
    else PORTB &= ~(1 << PB2);
  }
}