
unsigned long mod;
unsigned long freq;


void setup(){}

void loop(){
  
  freq = analogRead(A1)*256;
  mod = analogRead(A0)/4;

  delayMicroseconds(mod);
  analogWrite(A0, (micros()%freq)); 
}
