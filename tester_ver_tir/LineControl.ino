

void LineDeActive() {
  PORT_D_OFF;
  PORT_B_OFF;
  PORT_B_OUTPUT;
  PORT_D_OUTPUT;
  PORT_D_INPUT;
  PORT_B_INPUT;
}



void LineActive(byte pin_number, byte pin_DD) {
  LineDeActive();
  for (byte x = 0; x < sizeof(all_pin_user_DDR_Format); x++) {
    if ((all_pin_user_DDR_Format[x]) & (pin_DD)) {
      if (x <= 2) DDRD = DDRD | all_pin_DDR_Format[x];
      else DDRB = DDRB | all_pin_DDR_Format[x];
    }


    if ((all_pin_user_DDR_Format[x]) & (pin_number)) {
      if (x <= 2) PORTD = PORTD | all_pin_DDR_Format[x];
      else PORTB = PORTB | all_pin_DDR_Format[x];
    }
  }
}

void clear_volt_on_pin() {
  unsigned long t = millis();
  PORT_D_OFF;
  PORT_B_OFF;
  PORT_C_OFF;
  PORT_D_OUTPUT;
  PORT_B_OUTPUT;
  PORT_C_OUTPUT;
  while (analogRead(A0) > 0 || analogRead(A1) > 0 || analogRead(A2) > 0) {
    if (millis() > 5000 + t) {
    #ifdef serial  
      msg("message from clear volt pin function :  ");
      msg("very big capacitor");
      msg("can not discharjing .");
    #endif  
      break;
    }
  }
  PORT_D_INPUT;
  PORT_B_INPUT;
  PORT_C_INPUT;
}
