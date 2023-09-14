



// --------------------- global varible


void init__tester_ver_tir() {
  // chek line dont be have any volt on pin
  if (analogRead(pin_readLine1_const) > 0 || analogRead(pin_readLine2_const) > 0 || analogRead(pin_readLine3_const) > 0) {
    Serial.println("volt is on the line please clear vlot !");
    DDRB = 32;// B010000 sets PB5 as OUTPUT PB5 is 0010000 or 32 ); pin 13 or led pi = PORTB5
    PORT_C_INPUT;
    DDRD  = DDRD & 0b0 ;
    PORTD = PORTD & 0b0;
    DDRB  = DDRB & 0b0 ;
    PORTB = PORTB & 0b0;
  report_pin_debag();  
    
  }
}
