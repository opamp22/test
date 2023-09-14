enum part_type {
  resistance_kind,
  capacitor_kind,
  transistor_kind,
  thyristor_kind,
  triac_kind,
  led_kind,
  diode_kind,
  schottky_diode_kind,
  unknown_part_kind
};
const float adc_valu = 0.0048828125;
float answerResistor = 0.0, ChekanswerResistor = 0.0;
struct diod_properties {
  byte diod_count = 0;
  byte anod_diod1 = 0;
  byte catod_diod1 = 0;
  byte anod_diod2 = 0;
  byte catod_diod2 = 0;
};
diod_properties find_var_diod;

struct volt_pin_description {  //---> resistor and diod function
  int volt_line_1_2 = 0;
  int volt_line_2_1 = 0;
  int volt_line_2_3 = 0;
  int volt_line_3_2 = 0;
  int volt_line_1_3 = 0;
  int volt_line_3_1 = 0;

} var_pin_description;
float volt_all_pin_now_transistor[3] = { 0, 0, 0 };
struct Res_pin_where_struct {
  byte first_res_leg = 0;
  byte second_res_leg = 0;
} res_pinWhere;


bool tester_find_part_state = false;

const byte all_pin_DDR_Format[] { (1 << DDD3) // pin 3  // = 0b00001000 ; , 
                                 ,(1 << DDD5) // pin 5 // = 0b00100000 ;
                                 ,(1 << DDD6) // pin 6 // = 0b01000000 ;
                                 ,(1 << DDB1) // pin 9// = 0b00010 ;
                                 ,(1 << DDB2)// pin 10
                                 ,(1 << DDB3)// pin 11
                               }; 

const byte all_pin_user_DDR_Format[] {  0b100000   // pin 3  // = 0b00001000 ; , 
                                       ,0b010000 // pin 5 // = 0b00100000 ;
                                       ,0b001000 // pin 6 // = 0b01000000 ;
                                       ,0b000100 // pin 9// = 0b00010 ;
                                       ,0b000010 // pin 10
                                       ,0b000001// pin 11
                                       
                                     }; 
  const byte pin3  =   32     ;
  const byte pin5  =  (32>>1) ;
  const byte pin6  =  (32>>2) ;
  const byte pin9  =  (32>>3) ;
  const byte pin10 =  (32>>4) ;
  const byte pin11 =  (32>>5) ;
  