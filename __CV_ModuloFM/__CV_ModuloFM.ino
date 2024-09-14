

byte octave = 16;
byte beat = 0;
byte sahrate = 4;
byte beatlength = 16;


unsigned long loopcounts;

void setup(){}

void loop(){

  beat = analogRead(A1);
  beatlength = analogRead(A2);
  sahrate = analogRead(A2)%256;
  octave = beat % beatlength;
  
  delayMicroseconds(sahrate*octave/16);
  analogWrite(A0, (micros() ^ octave) % beat);  
}
