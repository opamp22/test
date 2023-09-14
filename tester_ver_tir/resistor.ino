boolean resistor() {
  Serial.println(F("resistor proccessing start ...."));
  part = resistance_kind;
  //******************** line1-2 ************************
  byte pin_mode = 0b101000;
  byte digital_direct = 0b100000;

  if (calculate_voltPin(part, pin_readLine1_const, pin_readLine2_const, digital_direct, pin_mode)) {  /// ----------------------- line 1 A0-->pin_readLine2_const
    ChekanswerResistor = answerResistor;
    // msg_show("ChekanswerResistor save last answer",ChekanswerResistor,0);
  }
  //******************** line2-1 ************************
  pin_mode = 0b101000;
  digital_direct = 0b001000;
  if (calculate_voltPin(part, pin_readLine2_const, pin_readLine1_const, digital_direct, pin_mode)) {
    if (chek_trutht_resistor()) {
      return true;
    } else {  // if line 1-2 and line 2-1 not equlse then ther is diod
      ChekanswerResistor = 0;

      ++find_var_diod.diod_count;
    }
  } else if (ChekanswerResistor) {
        ChekanswerResistor = 0;
    ++find_var_diod.diod_count;
  }
  //******************** line2-3 ************************
  digital_direct = 0b1000;
  pin_mode = 0b1010;
  if (calculate_voltPin(part, pin_readLine2_const, pin_readLine3_const, digital_direct, pin_mode)) {  /// ----------------------- line 2-3 pin_readLine2_const-->pin_readLine3_const
    ChekanswerResistor = answerResistor;
  }
  //******************** line3-2 ************************
  digital_direct = 0b0010;
  pin_mode = 0b1010;
  if (calculate_voltPin(part, pin_readLine3_const, pin_readLine2_const, digital_direct, pin_mode)) {
    if (chek_trutht_resistor()) {
      return true;
    } else {
      ChekanswerResistor = 0;
      ++find_var_diod.diod_count;
    }
  } else if (ChekanswerResistor) {
    ChekanswerResistor = 0;
    ++find_var_diod.diod_count;
  }
  //******************** line1-3 ************************
  digital_direct = 0b100000;
  pin_mode = 0b100010;
  if (calculate_voltPin(part, pin_readLine1_const, pin_readLine3_const, digital_direct, pin_mode)) {  /// ----------------------- line 3 A0-->pin_readLine3_const
    ChekanswerResistor = answerResistor;
  }
  //******************** line3-1 ************************
  digital_direct = 0b000010;
  pin_mode = 0b100010;
  if (calculate_voltPin(part, pin_readLine3_const, pin_readLine1_const, digital_direct, pin_mode)) {
    if (chek_trutht_resistor()) {
      return true;
    } else {
      ChekanswerResistor = 0;
      ++find_var_diod.diod_count;
    }
  } else if (ChekanswerResistor) {
    ChekanswerResistor = 0;
    ++find_var_diod.diod_count;
  }
  if (find_var_diod.diod_count > 0) {
    tester_find_part_state = true;
    find_var_diod.diod_count = 0;
    diod();
  }
  return false;
}
bool chek_trutht_resistor() {
  if (abs(ChekanswerResistor - answerResistor) < 2) {
    return true;
  } else {
    return false;
  }
  //*********************************************** end truth chek
}
