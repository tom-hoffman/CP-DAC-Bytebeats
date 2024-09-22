// incorporates code from Adafruit's accel_mouse.ino
// https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/accel_mouse/accel_mouse.ino
// Author: Tony DiCola
// License: MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

// Configuration values to adjust the sensitivity and speed of the mouse.
// X axis (left/right) configuration:
const float XACCEL_MIN = 0.1;      // Minimum range of X axis acceleration, values below
                            // this won't move the mouse at all.
const float XACCEL_MAX = 8.0;      // Maximum range of X axis acceleration, values above
                            // this will move the mouse as fast as possible.
const float XMOUSE_RANGE = 1023;   // Range of velocity for mouse movements.  The higher
                                 // this value the faster the mouse will move.
const float XMOUSE_SCALE = 1;      // Scaling value to apply to mouse movement, this is
                            // useful to set to -1 to flip the X axis movement.

// Y axis (up/down) configuration:
// Note that the meaning of these values is exactly the same as the X axis above,
// just applied to the Y axis and up/down mouse movement.  You probably want to
// keep these values the same as for the X axis (which is the default, they just
// read the X axis values but you can override with custom values).
const float YACCEL_MIN = XACCEL_MIN;
const float YACCEL_MAX = XACCEL_MAX;
const float YMOUSE_RANGE = XMOUSE_RANGE;
const float YMOUSE_SCALE = 1;

// Floating point linear interpolation function that takes a value inside one
// range and maps it to a new value inside another range.  This is used to transform
// each axis of acceleration to mouse velocity/speed. See this page for details
// on the equation: https://en.wikipedia.org/wiki/Linear_interpolation



byte octave = 16;
float beat = 0;
int sahrate = 4;
int beatlength = 16;

unsigned long loopcounts;

float lerp(float x, float x0, float x1, float y0, float y1) {
  // Check if the input value (x) is outside its desired range and clamp to
  // those min/max y values.
  if (x <= x0) {
    return y0;
  }
  else if (x >= x1) {
    return y1;
  }
  // Otherwise compute the value y based on x's position within its range and
  // the desired y min & max.
  return y0 + (y1-y0)*((x-x0)/(x1-x0));
}


void setup(){
  Serial.begin(9600);
  delay(1000);
  CircuitPlayground.begin();
}

void loop(){

  // Grab x, y acceleration values (in m/s^2).
  float x = CircuitPlayground.motionX();
  float y = CircuitPlayground.motionY();
  // Use the magnitude of acceleration to interpolate the mouse velocity.
  float x_mag = (abs(x));
  int beat = lerp(x_mag, XACCEL_MIN, XACCEL_MAX, 0.0, XMOUSE_RANGE);
  float y_mag = (abs(y));
  int beatLength = lerp(y_mag, YACCEL_MIN, YACCEL_MAX, 0.0, YMOUSE_RANGE);
  

  sahrate = beatlength%256;
  octave = beat % beatlength;
  delayMicroseconds(sahrate*octave/16);
  analogWrite(A0, (micros() ^ octave) % beat);  
}
