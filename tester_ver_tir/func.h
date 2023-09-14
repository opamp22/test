void LineActive(byte pin_number , byte pin_DD);
void LineDeActive() ;
boolean resistor(void);
boolean calculate_voltPin(part_type part,byte AnalogPin1,byte AnalogPin2,byte digital_direct,byte  pin_mode );
boolean transistor(String TRS_name) ;
float convertAnalogTO_volt( int valAnalog);
void draw_line_serial(void);
void init__tester_ver_tir();
bool cap();