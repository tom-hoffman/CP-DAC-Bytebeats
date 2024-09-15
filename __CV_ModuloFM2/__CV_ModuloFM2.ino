
int mod;
int freq;

void setup(){}

void loop(){

  freq = analogRead(A1)/32;
  mod = analogRead(A2)/32;
  
  delayMicroseconds(mod);
  analogWrite(A0, (micros() % freq));  
}
