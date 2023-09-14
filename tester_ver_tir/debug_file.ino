void report_pin_debag() {
  Serial.print("DDRD  : ");Serial.println(DDRD,BIN);
  Serial.print("PORTD : ");Serial.println(PORTD,BIN);
  Serial.print("DDRB  : ");Serial.println(DDRB,BIN);
  Serial.print("PORTB : ");Serial.println(PORTB,BIN);
  Serial.print("DDRC  : ");Serial.println(DDRC,BIN);
}
