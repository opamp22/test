#include <CapacitorLite.h>
#include <Capacitor.h>
#include <ezButton.h>
#include "definition.h"
#include "global_var.h"
#include <limits.h>
#include <TimerOne.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define serial
#define LCD
part_type part;
#include "func.h"
void waitting(long time_waitting);
boolean stateProccessing = false;
ezButton button(2);  // create ezButton object that attach to pin 7;
static unsigned int t,t1,t2;
#ifdef LCD
LiquidCrystal_I2C lcd(lcd_adreess, lcd_column, lcd_width);
#endif
void setup() {
#ifdef LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");
#endif
  init__tester_ver_tir();
#ifdef serial
  Serial.begin(9600);
  msg("tester is ready.");
#endif
}  // void setup
void loop() {
  print_tester();
  button.loop();
  if (button.isReleased()) {
    stateProccessing = true;
  }
  if (stateProccessing == true) {
    t = millis();
    if (resistor()) {
      LineDeActive();
#ifdef serial
      msg("finding res");
      msg_show("resistor is ", answerResistor, 2);
      msg("ohm");
#endif

      t = millis();

      stateProccessing = false;
    }
    if (cap()) {
      stateProccessing = false;
    } else if (self()) {
      stateProccessing = false;
    }
    stateProccessing = false;
  }  // if (stateProccessing == true) {
}

#ifdef serial
void print_tester() {
  if (millis() > t + 500) {
    msg("tester is ready.");
    t = millis();
  }
}
#endif