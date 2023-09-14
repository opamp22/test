
// start  -----------------------------------------------                                cap()
bool cap() {
  //********************************************************************** blok 1  finding cap
  byte analog_pin_capacitor_for_messuring = 0;
  byte pin1_indicator_for_mesure = 0;
  int val = 0, val_last = 0;
  // state 1
  if (calculate_pin_for_cap(pin3, pin3, A1, &val, &val_last)) {
    analog_pin_capacitor_for_messuring = A1;
    pin1_indicator_for_mesure = pin3;
    messure_capasitor( analog_pin_capacitor_for_messuring, pin1_indicator_for_mesure);
  } else if (val) {
    return false;
  }


  // state 2
  //----------
  if (calculate_pin_for_cap(pin3, pin3, A2, &val, &val_last)) {
    analog_pin_capacitor_for_messuring = A2;
    pin1_indicator_for_mesure = pin3;
    messure_capasitor( analog_pin_capacitor_for_messuring, pin1_indicator_for_mesure);
  } else if (val) {
    return false;
  }

  // state =3
  //----------
  if (calculate_pin_for_cap(pin6, pin6, A2, &val, &val_last)) {
    analog_pin_capacitor_for_messuring = A2;
    pin1_indicator_for_mesure = pin6;
    messure_capasitor( analog_pin_capacitor_for_messuring, pin1_indicator_for_mesure);
  } else if (val) {
    return false;
  }
  return false;
  // end  ----------------------------------------------    -                             cap()
}



bool val_test_for_finding(int val, int val_last) {
  if (val - val_last > 2) {
    return true;
  }
  return false;
}



bool calculate_pin_for_cap(byte pin, byte mod, byte pin_analog, int *val, int *val2) {
  byte pin2 = 0;
  unsigned long t1 = 0;
  LineActive(pin, mod);
  *(val) = analogRead(pin_analog);
  clear_volt_on_pin();
  if (*(val)) {
    LineActive(pin, mod);
    t1 = micros();
    while (micros() < 1000 + t1) {
      *(val2) = analogRead(pin_analog);
      if ((*(val) - *(val2)) > 2) {
        clear_volt_on_pin();
        return true;
      }
    }
    clear_volt_on_pin();
    switch (pin_analog) {
      case A1:
        pin2 = pin6;
        break;
      case A2:
        pin2 = pin10;
        break;
    }
    LineActive(pin, mod | pin2);
    *(val) = analogRead(pin_analog);
    t1 = millis();
    while (millis() < 1000 + t1) {
      *(val2) = analogRead(pin_analog);
      if ((*(val) - *(val2)) > 2) {
        clear_volt_on_pin();
        return true;
      }
    }
    clear_volt_on_pin();
    return false;
  } else {
    return false;
  }
}

void messure_capasitor( byte pin_indicator, byte pin_aval) {

  byte pin11, pin22;
  switch (pin_indicator) {
    case A1:
      pin11 = A0;
      pin22 = A1;
      break;
    case A2:
      if (pin_aval & pin3) {
        pin11 = A0;
        pin22 = A2;
      } else {
        pin11 = A1;
        pin22 = A2;
      }
      break;
  }
  msg_show("A0 ", A0,0);
  msg_show("A1 ", A1,0);
  msg_show("A2 ", A2,0);
  msg_show("pin11", pin11,0);
  msg_show(" pin22 ", pin22,0);
  CapacitorLite cap_CapacitorLite(pin11, pin22);
  Capacitor cap1_Capacitor(pin11, pin22);
  float answer_cap1_Capacitor = 0;
  unsigned int answer_cap_CapacitorLite = 0;
  answer_cap1_Capacitor = cap1_Capacitor.Measure();
  answer_cap_CapacitorLite = cap_CapacitorLite.Measure()/100.0;
  
    /*
    MeasureCapacitorLite

    Measures the capacitance between D7 and A2.
    Prints the result to the Serial Monitor.

    This is the "Lite" version. It uses a lot less program storage and is a lot quicker than the "Standard" version.
    However, it will only measure from 0.2pF to 655pF.
    Also, note that Measure() returns an unsigned int (pF * 100) rather than a float.

    For more detailed usage examples (e.g. liquid level measurement) and explanation of how the library works please see the wiki:
    https://github.com/codewrite/arduino-capacitor/wiki

    
*/
// Capacitor under test.
// Note that for electrolytics the first pin (in this case pin11)
// should be positive, the second (in this case pin22) negative.
    if (answer_cap_CapacitorLite < 750 ) {
       msg_show("capacitor little fun    pf ", answer_cap_CapacitorLite,0);  // Measure the capacitance (in pF), print to Serial Monitor
    }
    msg_show("capacitor big function  pf ", answer_cap1_Capacitor ,0);// Measure the capacitance (in pF), print to Serial Monitor
 
    
  /*
    MeasureCapacitor

    Measures the capacitance between D7 and A2.
    Prints the result to the Serial Monitor.

    
*/
   
  
}
