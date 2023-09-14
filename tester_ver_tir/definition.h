#pragma once
#define pin_11_const 3
#define pin_12_const 5
#define pin_21_const 6
#define pin_22_const 9
#define pin_31_const 10
#define pin_32_const 11
#define pin_readLine1_const A0
#define pin_readLine2_const A1
#define pin_readLine3_const A2
const byte pin_leg_array[] = { pin_11_const, pin_12_const, pin_21_const, pin_22_const,
                               pin_31_const, pin_32_const };


#define minimum_volt_ADC_can_to_be_read 0.0048828125

//---------------------------------------------------------------------
#define base_3_col_6_emiter_10_digital_direct 0b101000
#define base_3_col_6_emiter_10_pin_mode 0b101010
#define base_3_col_10_emiter_6_digital_direct 0b100010
#define base_3_col_10_emiter_6_pin_mode 0b101010
#define base_5_col_6_emiter_10_digital_direct 0b011000
#define base_5_col_6_emiter_10_pin_mode 0b011010
#define base_5_col_10_emiter_6_digital_direct 0b010010
#define base_5_col_10_emiter_6_pin_mode 0b011010
#define base_6_col_3_emiter_10_digital_direct 0b101000
#define base_6_col_3_emiter_10_pin_mode 0b101010
#define base_6_col_10_emiter_3_digital_direct 0b001010
#define base_6_col_10_emiter_3_pin_mode 0b101010
#define base_9_col_3_emiter_10_digital_direct 0b100100
#define base_9_col_3_emiter_10_pin_mode 0b100110
#define base_9_col_10_emiter_3_digital_direct 0b000110
#define base_9_col_10_emiter_3_pin_mode 0b100110
#define base_10_col_3_emiter_6_digital_direct 0b100010
#define base_10_col_3_emiter_6_pin_mode 0b101010
#define base_10_col_6_emiter_3_digital_direct 0b001010
#define base_10_col_6_emiter_3_pin_mode 0b101010
#define base_11_col_3_emiter_6_digital_direct 0b100001
#define base_11_col_3_emiter_6_pin_mode 0b101001
#define base_11_col_6_emiter_3_digital_direct 0b001001
#define base_11_col_6_emiter_3_pin_mode 0b101001
//************************************************************
#define PORT_D_ON  PORTD   = PORTD | 0b1101000
#define PORT_D_OFF PORTD   = PORTD & 0b0010111
#define PORT_D_OUTPUT DDRD = DDRD  | 0b1101000
#define PORT_D_INPUT DDRD  = DDRD  & 0b0010111

#define PORT_B_ON    PORTB = PORTB | 0b1110
#define PORT_B_OFF   PORTB = PORTB & 0b110001
#define PORT_B_OUTPUT DDRB =  DDRB | 0b1110
#define PORT_B_INPUT  DDRB =  DDRB & 0b110001


#define PORT_C_OUTPUT DDRC = DDRC | 0b1111
#define PORT_C_INPUT  DDRC  = DDRC  & 0b110000
#define PORT_C_OFF    PORTC = PORTC & 0b110000 ;
#define PIN_A3_ON  PORTC |=(1<<DDC3) ;
#define PIN_A3_OFF PORTC &=~(1<<DDC3) ;

#define PIN_3_ON  PORTD |=(1<<DDD3)
#define PIN_3_OFF PORTD &=~(1<<DDD3)

#define PIN_5_ON  PORTD |=(1<<DDD5)
#define PIN_5_OFF PORTD &=~(1<<DDD5)
 
#define PIN_6_ON  PORTD |= (1<<DDD6)
#define PIN_6_OFF PORTD &=~(1<<DDD6)

#define PIN_9_ON  PORTB |= (1<<DDB1)
#define PIN_9_OFF PORTB &=~(1<<DDB1)

#define PIN_10_ON  PORTB |= (1<<DDB2)
#define PIN_10_OFF PORTB &=~(1<<DDB2)

#define PIN_11_ON  PORTB |= (1<<DDB3)
#define PIN_11_OFF PORTB &=~(1<<DDB3)

#define PIN_13_ON  PORTB |= (1<<DDB5)
#define PIN_13_OFF PORTB &=~(1<<DDB5)
//************** Lcd peroperties I2c lcd
#define lcd_adreess 0x38
#define lcd_column 20
#define lcd_width 4
//************************
