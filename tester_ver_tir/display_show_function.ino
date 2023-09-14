#ifdef serial
void msg(String c) {
  Serial.println((c));
}


void msg1(byte b) {
  Serial.println(b, BIN);
}


void msg_show(String c, float f,byte x) {
  Serial.print((c));
  Serial.print(F(" = "));
  Serial.println(f, x);
}
#endif