# Circuit Playground Express DAC Bytebeats

Circuit Playground port of experimental synthesizers using various arbitrary math to create audio output on the teensy 3.1 DAC pin.

Direct fork of https://github.com/MacroMachines/Teensy-DAC-Bytebeats to work out of the box with the Adafruit Circuit Playground.

The primary trivial change is switching the DAC pin from A14 (teensy 3.1) to A0 (Circuit Playground Express).  

The files starting with __CV_ take control voltages through two pins.  I did a little experimenting with using the accelerometer
for these inputs but didn't find it too satisfying.

Not all are done... see the commit notes and dates to figure it out.

several vine clips of the sketches in action: 
https://vine.co/v/OijKltQbXv0
https://vine.co/v/O5BAiOz3qJO
https://vine.co/v/O57mAVlLZz0

