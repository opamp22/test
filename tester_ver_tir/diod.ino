#define Diode_identification_number 213
void diod() {
  part = diode_kind;
  byte count_diod = 0;
  // Serial.println(F("diod proccessing start ...."));
  // Serial.print(F("volt_line_1_2  "));
  // Serial.println(convertAnalogTO_volt(var_pin_description.volt_line_1_2) * 1000);
  // Serial.print(F("volt_line_2_1  "));
  // Serial.println(convertAnalogTO_volt(var_pin_description.volt_line_2_1) * 1000);
  // Serial.print(F("volt_line_2_3  "));
  // Serial.println(convertAnalogTO_volt(var_pin_description.volt_line_2_3) * 1000);
  // Serial.print(F("volt_line_3_2  "));
  // Serial.println(convertAnalogTO_volt(var_pin_description.volt_line_3_2) * 1000);
  // Serial.print(F("volt_line_1_3  "));
  // Serial.println(convertAnalogTO_volt(var_pin_description.volt_line_1_3) * 1000);
  // Serial.print(F("volt_line_3_1  "));
  // Serial.println(convertAnalogTO_volt(var_pin_description.volt_line_3_1) * 1000);


  if (var_pin_description.volt_line_1_2 < Diode_identification_number) {
    ++count_diod;
    Serial.println(F(" -------------> : diod properties ......"));
    Serial.print("anod_diod  ");
    Serial.print(count_diod);

    Serial.print("  =   ");
    Serial.println(" pin 3.");
    Serial.print("catod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 6.");
    find_var_diod.anod_diod1 = 3;
    find_var_diod.catod_diod1 = 6;
  }
  if (var_pin_description.volt_line_2_1 < Diode_identification_number) {
    Serial.println(F(" <------------- : diod properties ......"));
    ++count_diod;
    Serial.print("anod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 6.");
    Serial.print("catod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 3.");
    if (count_diod == 2) {
      find_var_diod.anod_diod2 = 6;
      find_var_diod.catod_diod2 = 3;
    } else {
      find_var_diod.anod_diod1 = 6;
      find_var_diod.catod_diod1 = 3;
    }
  }
  if (var_pin_description.volt_line_2_3 < Diode_identification_number) {
    Serial.println(F(" -------------> : diod properties ......"));
    ++count_diod;
    Serial.print("anod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 6.");
    Serial.print("catod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 10.");
    if (count_diod == 2) {
      find_var_diod.anod_diod2 = 6;
      find_var_diod.catod_diod2 = 10;
    } else {
      find_var_diod.anod_diod1 = 6;
      find_var_diod.catod_diod1 = 10;
    }
  }
  if (var_pin_description.volt_line_3_2 < Diode_identification_number) {
    Serial.println(F(" <------------- : diod properties ......"));
    ++count_diod;
    Serial.print("anod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 10.");
    Serial.print("catod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 6.");
    if (count_diod == 2) {
      find_var_diod.anod_diod2 = 10;
      find_var_diod.catod_diod2 = 6;
    } else {
      find_var_diod.anod_diod1 = 10;
      find_var_diod.catod_diod1 = 6;
    }
  }
  if (var_pin_description.volt_line_1_3 < Diode_identification_number) {
    Serial.println(F(" -------------> : diod properties ......"));
    ++count_diod;
    Serial.print("anod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 3.");
    Serial.print("catod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 10.");
    if (count_diod == 2) {
      find_var_diod.anod_diod2 = 3;
      find_var_diod.catod_diod2 = 10;
    } else {
      find_var_diod.anod_diod1 = 3;
      find_var_diod.catod_diod1 = 10;
    }
  }
  if (var_pin_description.volt_line_3_1 < Diode_identification_number) {
    Serial.println(F(" <------------- : diod properties ......"));
    ++count_diod;
    Serial.print("anod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 10.");
    Serial.print("catod_diod  ");
    Serial.print(count_diod);
    Serial.print("  =   ");
    Serial.println(" pin 3.");
    if (count_diod == 2) {
      find_var_diod.anod_diod2 = 10;
      find_var_diod.catod_diod2 = 3;
    } else {
      find_var_diod.anod_diod1 = 10;
      find_var_diod.catod_diod1 = 3;
    }
  }
  clear_volt_on_pin();
  //******************************************************************************************************
  //**************** Investigating the possibility of having a transistor ********************************
  //******************************************************************************************************
  if (count_diod == 2) {
    if (find_var_diod.catod_diod1 == find_var_diod.catod_diod2) { msg("trs chek");
      if (transistor("PNP")) {

      } else {
        Serial.println("it is not transistor ");
      }
    }
    if (find_var_diod.anod_diod1 == find_var_diod.anod_diod2) {msg("trs chek");
      if (transistor("NPN")) {

      } else {
        Serial.println("it is not transistor ");
      }
    }
  }
}
