bool self() {

  

double pulse=0 ,ferecance=0 ,capacitance=0 , inductance=0 ,inductance_mh=0 ; 



DDRC |=(1<<DDC3);
PIN_A3_ON ;
waitting(20000);
// delay(5);
PIN_A3_OFF ;
// delayMicroseconds(100);
waitting(400);
pulse = pulseIn(13,HIGH,5000);
if (pulse > .1) {
capacitance =2.E-6;


ferecance =1.E6 / (2*pulse);
inductance = 1./(capacitance * ferecance *ferecance *4.*3.14159*3.14159) ;
inductance *=1E6 ;
inductance_mh = inductance / 1000 ;
msg_show("pulse",pulse,0);
msg_show("ferecance ",ferecance,0);
msg_show("inductance ",inductance,0);
msg_show("inductance Mili H " ,inductance_mh,5);
return true;
}
  return false;
}


