
bool Examining_possible_transistor_conditions(byte count);
void setting_possible_transistor_specification(byte count, byte andis_base_pin, byte andis_col_pin, byte andis_emietr_pin);
void set_transistor_pin(byte *b_pin, byte *c_pin, byte *e_pin, byte *andis_base_pin, byte *andis_col_pin, byte *andis_emit_pin, byte count);
boolean transistor(String TRS_name) {
  part = transistor_kind;
  byte digital_direct = 0, pin_mode = 0;
  Serial.println(F(" transistor proccessing start ."));
  draw_line_serial();
  if (TRS_name == "NPN") {  // if npn transistor is a reall
    switch (find_var_diod.anod_diod1) {

      case 3:  // base =3
        // farz col =6 va emiter = 10
        digital_direct = base_3_col_6_emiter_10_digital_direct;
        pin_mode = base_3_col_6_emiter_10_pin_mode;
        if (searching_transistor(digital_direct, pin_mode, pin_11_const, pin_21_const, pin_31_const)) {
          Serial.println(F(" result calculating start ."));
          if ((prop_bayas_storage_struct[0].grade_point_codishen_trs_bjt + prop_bayas_storage_struct[2].grade_point_codishen_trs_bjt) < (prop_bayas_storage_struct[1].grade_point_codishen_trs_bjt + prop_bayas_storage_struct[3].grade_point_codishen_trs_bjt)) {
            result_calculating_analize_transistor(1);
            return true;
          } else {
            result_calculating_analize_transistor(0);
            return true;
          }
        }
        break;
      case 6:  // base =6
        // farz col =3 va emiter = 10
        Serial.println(F("base resistor is 680 ohm ...."));
        digital_direct = base_6_col_3_emiter_10_digital_direct;
        pin_mode = base_6_col_3_emiter_10_pin_mode;
        if (searching_transistor(digital_direct, pin_mode, pin_21_const, pin_11_const, pin_31_const)) {
          Serial.println(F(" result calculating start ."));
          if ((prop_bayas_storage_struct[0].grade_point_codishen_trs_bjt + prop_bayas_storage_struct[2].grade_point_codishen_trs_bjt) < (prop_bayas_storage_struct[1].grade_point_codishen_trs_bjt + prop_bayas_storage_struct[3].grade_point_codishen_trs_bjt)) {
            result_calculating_analize_transistor(1);
            return true;
          } else {
            result_calculating_analize_transistor(0);
            return true;
          }
        }
        break;
      case 10:  // base =10
        // farz col =3 va emiter = 6
        Serial.println(F("base resistor is 680 ohm ...."));
        digital_direct = base_10_col_3_emiter_6_digital_direct;
        pin_mode = base_10_col_3_emiter_6_pin_mode;
        if (searching_transistor(digital_direct, pin_mode, pin_31_const, pin_11_const, pin_21_const)) {
          Serial.println(F(" result calculating start ."));
          if ((prop_bayas_storage_struct[0].grade_point_codishen_trs_bjt + prop_bayas_storage_struct[2].grade_point_codishen_trs_bjt) < (prop_bayas_storage_struct[1].grade_point_codishen_trs_bjt + prop_bayas_storage_struct[3].grade_point_codishen_trs_bjt)) {
            result_calculating_analize_transistor(1);
            return true;
          } else {
            result_calculating_analize_transistor(0);
            return true;
          }
        }
        break;
    }

  }  // **** NPN transistor
  if (TRS_name == "PNP") {
  }
  return false;
}  // boolean transistor(String TRS_name) {

//*************************************************************************   result_calculating_analize_transistor(bool c)
void result_calculating_analize_transistor(bool c) {
  float b;
  b = hfe_finder(c);
  draw_line_serial();
  draw_line_serial();
  Serial.print(F("transistor state is : "));
  Serial.println(c + 1);
  draw_line_serial();
  draw_line_serial();
  Serial.print(" HFE                 : ");
  Serial.println(b, 2);
  draw_line_serial();
}
//*************************************************end   *******************   result_calculating_analize_transistor(bool c)
bool searching_transistor(byte digital_direct, byte pin_mode, byte b_pin, byte c_pin, byte e_pin) {
  byte andis_col_pin, andis_emiter_pin, andis_base_pin;
  byte counting_transistor_wiring_steps = 0;

  prop_bayas_storage_struct[0].vb_pin_codishen_trs_bjt = b_pin;
  prop_bayas_storage_struct[0].vc_pin_codishen_trs_bjt = c_pin;
  prop_bayas_storage_struct[0].ve_pin_codishen_trs_bjt = e_pin;

  ++counting_transistor_wiring_steps;
  Serial.print(F("counting_transistor_wiring_steps : "));
  Serial.println(counting_transistor_wiring_steps);
  set_transistor_pin(&b_pin, &c_pin, &e_pin, &andis_base_pin, &andis_col_pin, &andis_emiter_pin, counting_transistor_wiring_steps);
  calculate_voltPin(part, 1, 1, digital_direct, pin_mode);
  setting_possible_transistor_specification(counting_transistor_wiring_steps, andis_base_pin, andis_col_pin, andis_emiter_pin);
  print_transistor_properties(counting_transistor_wiring_steps);



  ++counting_transistor_wiring_steps;
  Serial.print(F("counting_transistor_wiring_steps : "));
  Serial.println(counting_transistor_wiring_steps);
  set_transistor_pin(&b_pin, &c_pin, &e_pin, &andis_base_pin, &andis_col_pin, &andis_emiter_pin, counting_transistor_wiring_steps);
  adjastable_digital_direct_and_pinMOde(&digital_direct, &pin_mode, counting_transistor_wiring_steps, b_pin);
  calculate_voltPin(part, 1, 1, digital_direct, pin_mode);
  setting_possible_transistor_specification(counting_transistor_wiring_steps, andis_base_pin, andis_col_pin, andis_emiter_pin);
  print_transistor_properties(counting_transistor_wiring_steps);



  ++counting_transistor_wiring_steps;
  Serial.print(F("counting_transistor_wiring_steps : "));
  Serial.println(counting_transistor_wiring_steps);
  set_transistor_pin(&b_pin, &c_pin, &e_pin, &andis_base_pin, &andis_col_pin, &andis_emiter_pin, counting_transistor_wiring_steps);
  adjastable_digital_direct_and_pinMOde(&digital_direct, &pin_mode, counting_transistor_wiring_steps, b_pin);
  calculate_voltPin(part, 1, 1, digital_direct, pin_mode);
  setting_possible_transistor_specification(counting_transistor_wiring_steps, andis_base_pin, andis_col_pin, andis_emiter_pin);
  print_transistor_properties(counting_transistor_wiring_steps);



  ++counting_transistor_wiring_steps;
  Serial.print(F("counting_transistor_wiring_steps : "));
  Serial.println(counting_transistor_wiring_steps);
  set_transistor_pin(&b_pin, &c_pin, &e_pin, &andis_base_pin, &andis_col_pin, &andis_emiter_pin, counting_transistor_wiring_steps);
  adjastable_digital_direct_and_pinMOde(&digital_direct, &pin_mode, counting_transistor_wiring_steps, b_pin);
 
  calculate_voltPin(part, 1, 1, digital_direct, pin_mode);
  

  setting_possible_transistor_specification(counting_transistor_wiring_steps, andis_base_pin, andis_col_pin, andis_emiter_pin);
   print_transistor_properties(counting_transistor_wiring_steps);
  return true;
}
void set_transistor_pin(byte *b_pin, byte *c_pin, byte *e_pin, byte *andis_base_pin, byte *andis_col_pin, byte *andis_emit_pin, byte count) {
  Serial.println(F("set_transistor_pin() "));

  switch (*(b_pin)) {
    case 3:
      if (count == 3) {
        *(b_pin) = 5;
        *(c_pin) = 6;
        *(e_pin) = 10;
      }
      if (count == 2) {
        *(c_pin) = 10;
        *(e_pin) = 6;
      }
      break;
    case 5:
      *(c_pin) = 10;
      *(e_pin) = 6;
      break;
    case 6:
      if (count == 3) {
        *(b_pin) = 9;
        *(c_pin) = 3;
        *(e_pin) = 10;
      }
      if (count == 2) {
        *(c_pin) = 10;
        *(e_pin) = 3;
      }
      break;
    case 9:
      *(c_pin) = 10;
      *(e_pin) = 3;
      break;
    case 10:
      if (count == 3) {
        *(b_pin) = 11;
        *(c_pin) = 3;
        *(e_pin) = 6;
      }
      if (count == 2) {
        *(c_pin) = 6;
        *(e_pin) = 3;
      }
      break;
    case 11:
      *(c_pin) = 6;
      *(e_pin) = 3;
      break;
  }

  switch (*(b_pin)) {
    case 6:
      *(andis_base_pin) = 1;
      break;
    case 9:
      *(andis_base_pin) = 1;
      break;
    case 5:
      *(andis_base_pin) = 0;
      break;
    case 3:
      *(andis_base_pin) = 0;
      break;
    case 10:
      *(andis_base_pin) = 2;
      break;
    case 11:
      *(andis_base_pin) = 2;
      break;
  }
  switch (*(c_pin)) {
    case 6:
      *(andis_col_pin) = 1;
      break;
    case 3:
      *(andis_col_pin) = 0;
      break;
    case 10:
      *(andis_col_pin) = 2;
      break;
  }
  switch (*(e_pin)) {
    case 6:
      *(andis_emit_pin) = 1;
      break;
    case 3:
      *(andis_emit_pin) = 0;
      break;
    case 10:
      *(andis_emit_pin) = 2;
      break;
  }
  prop_bayas_storage_struct[count - 1].vb_pin_codishen_trs_bjt = *(b_pin);
  prop_bayas_storage_struct[count - 1].vc_pin_codishen_trs_bjt = *(c_pin);
  prop_bayas_storage_struct[count - 1].ve_pin_codishen_trs_bjt = *(e_pin);
}
void adjastable_digital_direct_and_pinMOde(byte *digi, byte *pinmod, byte count, byte basePin) {
 
   switch (basePin) {
    case 3:
      *(digi) = base_3_col_10_emiter_6_digital_direct;
      *(pinmod) = base_3_col_10_emiter_6_pin_mode;
      break;
    case 5:
      if (count == 3) {
        *(digi) = base_5_col_6_emiter_10_digital_direct;
        *(pinmod) = base_5_col_6_emiter_10_pin_mode;
      } else if (count == 4) {
        *(digi) = base_5_col_10_emiter_6_digital_direct;
        *(pinmod) = base_5_col_10_emiter_6_pin_mode;
      }
      break;
    case 6:

      *(digi) = base_6_col_10_emiter_3_digital_direct;
      *(pinmod) = base_6_col_10_emiter_3_pin_mode;

      break;
    case 9:
      if (count == 3) {
        *(digi) = base_9_col_3_emiter_10_digital_direct;
        *(pinmod) = base_9_col_3_emiter_10_pin_mode;
      } else if (count == 4) {
        *(digi) = base_9_col_10_emiter_3_digital_direct;
        *(pinmod) = base_9_col_10_emiter_3_pin_mode;
      }
      break;
    case 10:

      *(digi) = base_10_col_6_emiter_3_digital_direct;
      *(pinmod) = base_10_col_6_emiter_3_pin_mode;

      break;
    case 11:
      if (count == 3) {
        *(digi) = base_11_col_3_emiter_6_digital_direct;
        *(pinmod) = base_11_col_3_emiter_6_pin_mode;
      } else if (count == 4) {
        *(digi) = base_11_col_6_emiter_3_digital_direct;
        *(pinmod) = base_11_col_6_emiter_3_pin_mode;
      }

      break;
  }
 
}
float hfe_finder(bool c) {
  Serial.println(F("hfe start "));delay(2000);
  LineDeActive();  // line is of
   Serial.println(F("LineDeActive(); "));delay(2000);
  byte emiter_pin_read_analog = 0;
  byte colect_read_analog_pin = 0;
  byte base_read_analog_pin = 0;
  byte pin_b, pin_c, pin_e;
  byte digital_direct = 0, pin_mode = 0;
  pin_b = prop_bayas_storage_struct[c].vb_pin_codishen_trs_bjt;
  pin_c = prop_bayas_storage_struct[c].vc_pin_codishen_trs_bjt;
  pin_e = prop_bayas_storage_struct[c].ve_pin_codishen_trs_bjt;



  float col_volt = 0.0;
  float base_volt = 0.0;
  if (pin_b == 3) {
    base_read_analog_pin = A0;
    digital_direct = digital_direct | 0b010000;  // active 470 k  resistor
    pin_mode = pin_mode | 0b010000;
  }

  if (pin_c == 3) {
    colect_read_analog_pin = A0;
    digital_direct = digital_direct | 0b100000;  // --
    pin_mode = pin_mode | 0b100000;
  }

  if (pin_e == 3) {
    emiter_pin_read_analog = A0;
  }

  if (pin_b == 6) {
    base_read_analog_pin = A1;
    digital_direct = digital_direct | 0b000100;  // active 470 k  resistor
    pin_mode = pin_mode | 0b000100;
  }
  if (pin_c == 6) {
    colect_read_analog_pin = A1;
    digital_direct = digital_direct | 0b001000;  //----
    pin_mode = pin_mode | 0b001000;
  }
  if (pin_e == 6) {
    emiter_pin_read_analog = A1;
  }

  if (pin_b == 10) {
    base_read_analog_pin = A2;
    digital_direct = digital_direct | 0b1;  // active 470 k  resistor
    pin_mode = pin_mode | 0b1;
  }
  if (pin_c == 10) {
    colect_read_analog_pin = A2;
    digital_direct = digital_direct | 0b10;
    pin_mode = pin_mode | 0b10;
  }
  if (pin_e == 10) {
    emiter_pin_read_analog = A2;
  }
   Serial.print(digital_direct,BIN);Serial.println(F("   digital_direct"));
  Serial.print(pin_mode,BIN);Serial.println(F("   pin_mode"));

  Serial.println(F("befor setting "));delay(2000);
  pinMode(emiter_pin_read_analog, OUTPUT);
  LineActive(digital_direct, pin_mode);



  col_volt = convertAnalogTO_volt(analogRead(colect_read_analog_pin));
  base_volt = convertAnalogTO_volt(analogRead(base_read_analog_pin));
  float x, y, z;
  x = ((5 - col_volt) / 680.0) * 1000;
  y = ((5 - base_volt) / 470000.0) * 1000;
  z = (x / y);
  Serial.print(F("col_volt : "));
  Serial.println(col_volt, 5);
  Serial.print(F("base_volt: "));
  Serial.println(base_volt, 5);
  Serial.print(F("x=(5-col_volt)/680.0) : "));
  Serial.println(x, 5);
  Serial.print(F("(5-base_volt)/470000.0) : "));
  Serial.println(y, 5);
  Serial.print(F("x/y : "));
  Serial.println(z, 2);

 
   LineDeActive();  // line is of
   return (((5 - col_volt) / 680.0) / ((5 - base_volt) / 470000.0));
 
  /*  const float f = 691.17647;  // 470k / 680
  return (int)(((5 - transis_struct_var.colect_volt) / (5 - transis_struct_var.base_volt)) * f);*/
}
void print_transistor_properties(byte count) {
  draw_line_serial();
  Serial.print(F("transistor is a "));
  draw_line_serial();
  Serial.print(F(" Collector pin is    : "));
  Serial.println(prop_bayas_storage_struct[count - 1].vc_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" Base pin is         : ");
  Serial.println(prop_bayas_storage_struct[count - 1].vb_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" emiter pin is       : ");
  Serial.println(prop_bayas_storage_struct[count - 1].ve_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" colector voltaj     : ");
  Serial.println(prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" base voltaj         : ");
  Serial.println(prop_bayas_storage_struct[count - 1].volt_base_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" emiter voltaj       : ");
  Serial.println(prop_bayas_storage_struct[count - 1].volt_emiter_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" 500<= VB - VC <=1200: ");
  Serial.println(prop_bayas_storage_struct[count - 1].volt_base_pin_codishen_trs_bjt - prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.print(" VC_VE               : ");
  Serial.println(prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt - prop_bayas_storage_struct[count - 1].volt_emiter_pin_codishen_trs_bjt);
  draw_line_serial();
  Serial.println("waitting ...");
  draw_line_serial();
  // waitting(1000);
}
void setting_possible_transistor_specification(byte count, byte andis_base_pin, byte andis_col_pin, byte andis_emietr_pin) {
   prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt = volt_all_pin_now_transistor[andis_col_pin] * 1000;
  prop_bayas_storage_struct[count - 1].volt_base_pin_codishen_trs_bjt = volt_all_pin_now_transistor[andis_base_pin] * 1000;
  prop_bayas_storage_struct[count - 1].volt_emiter_pin_codishen_trs_bjt = volt_all_pin_now_transistor[andis_emietr_pin] * 1000;
    
  if (Examining_possible_transistor_conditions(count)) {
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------state_bayas_transistor()
bool Examining_possible_transistor_conditions(byte count) {



  float var = 0;
  /// shart 1 manfi vc>=4800
  if (prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt >= 4800) {
    Serial.println(F("vc>=4800"));

    prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt -= 5;
    prop_bayas_storage_struct[count - 1].vc_biggerThan4800_codishen_trs_bjt = true;
    prop_bayas_storage_struct[count - 1].ts_off_codishen_trs_bjt = true;

    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);
    Serial.println(F(" transistor is off and procceessing is stop and other proc is start : "));
    return false;
  }


  /// shart 2 manfi ve>=4800
  if (prop_bayas_storage_struct[count - 1].volt_emiter_pin_codishen_trs_bjt >= 4800) {
    Serial.println(F("ve>=4800"));

    --prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;
    prop_bayas_storage_struct[count - 1].ve_biggerThan4800_codishen_trs_bjt = true;
    prop_bayas_storage_struct[count - 1].ts_off_codishen_trs_bjt = true;


    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);
  }



  
  //***shart 3  500<=Vb-Vc<=1200
  var = prop_bayas_storage_struct[count - 1].volt_base_pin_codishen_trs_bjt - prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt;
  if (var >= 500 && var <= 1200) {

    prop_bayas_storage_struct[count - 1].reson_500_Vb_Vc_1200_codishen_trs_bjt_bool = true;
    Serial.println(F("becuse 500<= Vb-Vc <= 1200   "));
    ++prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;

    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);

    if (!(count % 2)) {  // shart 4 vb1>vb2
      if (prop_bayas_storage_struct[count - 2].reson_500_Vb_Vc_1200_codishen_trs_bjt_bool) {
        Serial.println(F("shart vb1>vb2  : "));
        if (prop_bayas_storage_struct[count - 1].volt_base_pin_codishen_trs_bjt - prop_bayas_storage_struct[count - 2].volt_base_pin_codishen_trs_bjt < 0) {
          ++prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;

          Serial.print(F("grade_point_codishen_trs_bjt  : "));
          Serial.print(count);
          Serial.print(F(" is  : "));
          Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);

        } else {
          ++prop_bayas_storage_struct[count - 2].grade_point_codishen_trs_bjt;

          Serial.print(F("grade_point_codishen_trs_bjt  : "));
          Serial.print(count - 1);
          Serial.print(F(" is  : "));
          Serial.println(prop_bayas_storage_struct[count - 2].grade_point_codishen_trs_bjt);
        }
      }
    }
    // *** shart 5 vb-vc <=0
  } else if (var <= 0) {

    if (count <= 2) {
      --prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;
      Serial.println(F("shart manfi becuse vb-vc <=0    ..... r=680   ***"));
    } else if (var >= -4800) {
      ++prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;
      Serial.println(F("shart mosbat becuse -4800<vb-vc <=0    ..... r=470k   ***"));
    }


    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);
  }

  
  // shart mosbat 6  Vc- ve <= 110 shart mosbat***************************************************************                             0<=  vc-ve <110
  var = prop_bayas_storage_struct[count - 1].volt_colect_pin_codishen_trs_bjt - prop_bayas_storage_struct[count - 1].volt_emiter_pin_codishen_trs_bjt;
  if (var <= 110 && var >= 0) {
    Serial.println(F(" becuse 0=<vc-ve<=110 "));


    prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt += 1;

    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);

    // shart 7                                                                                                           Vc-ve > 4800
  } else if (var > 4800) {
    Serial.println(F("Vc-ve > 4800 shart manfi "));
    --prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;

    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);

    // shart 8                                                                                                          Vc-ve < 0
  } else if (var < 0) {

    Serial.println(F("Vc-ve < 0 shart manfi "));
    --prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;

    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);
    // shart 9 manfi 4800>Vc- ve >110 if r_base = 680 ohm => shart is manfi  and if r=470k => shart is mosbat        4800>Vc- ve >110
  } else if (var < 4800 && var > 110) {

    if (count <= 2) {
      --prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;
      Serial.println(F("shart manfi 4800>Vc- ve >110 ..... r=680   ***"));
    } else {
      ++prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt;
      Serial.println(F("shart mosbat 4800>Vc- ve >110 ..... r=470k   **** "));
    }
    Serial.print(F("grade_point_codishen_trs_bjt  : "));
    Serial.print(count);
    Serial.print(F(" is  : "));
    Serial.println(prop_bayas_storage_struct[count - 1].grade_point_codishen_trs_bjt);
  }
 
  return true;

}  // --------------------------------------------------end------------------------------  Examining_possible_transistor_conditions(byte count) {
