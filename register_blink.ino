const int led_pin = PB7;
const uint16_t t1_load = 0;
const uint16_t t1_compare = 31250;

void setup() {
  // port B data direction port register. 
  DDRB = 0x80;
  // reset timer control register 
  TCCR5A = 0x00;

  // set the 256 bit prescaler
  // page 157 of the mega 2560 manual
  TCCR5B = 0x04;
  
  // reset timer 1 and set compare variable
  TCNT5 = t1_load;    // 0
  OCR5A = t1_compare; // 31250

  // Timer interrupt mask register enable timer 1 compare interrupt
  TIMSK5 = 0x02;
  // enable global interrupts
  sei(); 
}

void loop() {
  delay(500);
}
ISR(TIMER5_COMPA_vect){
  TCNT5 = t1_load;
  PORTB ^= (1 << led_pin);
}
