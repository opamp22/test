float convertAnalogTO_volt(int valAnalog) {
  return minimum_volt_ADC_can_to_be_read * (float)valAnalog;
}

//********************** draw line in serial monitor *********************
void draw_line_serial() {
  for (int x = 0; x < 35; x++) {
    Serial.print("-");
  }
  Serial.println("");
}
//************************************************************************

// *************************************** calculate_voltPin(part_type part,

boolean calculate_voltPin(part_type part, byte AnalogPin1, byte AnalogPin2, byte digital_direct, byte pin_mode) {
LineActive(digital_direct, pin_mode);
 byte andis_transistor_volt_array = 0;
  andis_transistor_volt_array = 0;
  int s = 0, d = 0;
  if (part == resistance_kind) {
    s = analogRead(AnalogPin1);
    d = analogRead(AnalogPin2);
  }
  if (part == transistor_kind) {
    volt_all_pin_now_transistor[andis_transistor_volt_array++] = convertAnalogTO_volt(analogRead(pin_readLine1_const));
    waitting(1);
    volt_all_pin_now_transistor[andis_transistor_volt_array++] = convertAnalogTO_volt(analogRead(pin_readLine2_const));
    waitting(1);
    volt_all_pin_now_transistor[andis_transistor_volt_array++] = convertAnalogTO_volt(analogRead(pin_readLine3_const));
    waitting(1);
     return true;
  }
  /// ***********   line 1-2
  if (AnalogPin1 == pin_readLine1_const && AnalogPin2 == pin_readLine2_const) {
    res_pinWhere.first_res_leg = 1;
    res_pinWhere.second_res_leg = 2;
    var_pin_description.volt_line_1_2 = s - d;
  }
  /// ***********   line 2-1
  if (AnalogPin1 == pin_readLine2_const && AnalogPin2 == pin_readLine1_const) {
    var_pin_description.volt_line_2_1 = s - d;
  }
  /// ***********   line 2-3
  if (AnalogPin1 == pin_readLine2_const && AnalogPin2 == pin_readLine3_const) {
    res_pinWhere.first_res_leg = 2;
    res_pinWhere.second_res_leg = 3;
    var_pin_description.volt_line_2_3 = s - d;
  }
  /// ***********   line 3-2
  if (AnalogPin1 == pin_readLine3_const && AnalogPin2 == pin_readLine2_const) {
    res_pinWhere.first_res_leg = 2;
    res_pinWhere.second_res_leg = 3;
    var_pin_description.volt_line_3_2 = s - d;
  }

  /// ***********   line 1-3
  if (AnalogPin1 == pin_readLine1_const && AnalogPin2 == pin_readLine3_const) {
    res_pinWhere.first_res_leg = 1;
    res_pinWhere.second_res_leg = 3;
    var_pin_description.volt_line_1_3 = s - d;
  }
  /// ***********   line 1-3
  if (AnalogPin1 == pin_readLine3_const && AnalogPin2 == pin_readLine1_const) {
    res_pinWhere.first_res_leg = 1;
    res_pinWhere.second_res_leg = 3;
    var_pin_description.volt_line_3_1 = s - d;
  }
  if (part == resistance_kind) {
    if (d) {
      answerResistor = ((float)(s - d) / (float)d) * 680;
      // msg_show("answerResistor ",answerResistor,0);
      // delay(1000);
      return true;
    } else {
      return false;
    }
  }  //   if (part == resistance_kind) {
  return false;
}
void waitting(int time_waitting) {
  for (int c = 0; c < time_waitting; c++) {
    asm("");
  }
}