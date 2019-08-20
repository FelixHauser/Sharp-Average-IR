/************************************************************************************************************
 * SharpAverageIR.h (formely SharpIR)- Arduino library for retrieving distance (in cm) from the analog      *
 * GP2Y0A21Y and GP2Y0A02YK distance sensors                                                                *
 * Copyright 2014-2019 Felix Hauser                                                                         *
 * Last update: 19.08.2019                                                                                  *
 ************************************************************************************************************

 ************************************************************************************************************
 * This library is free software; you can redistribute it and/or                                            *
 * modify it under the terms of the GNU Lesser General Public                                               *
 * License as published by the Free Software Foundation; either                                             *
 * version 2.1 of the License, or (at your option) any later version.                                       *
 *                                                                                                          *
 * This library is distributed in the hope that it will be useful,                                          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                                           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                                        *
 * Lesser General Public License for more details.                                                          *
 *                                                                                                          *
 * You should have received a copy of the GNU Lesser General Public                                         *
 * License along with this library; if not, write to the Free Software                                      *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                               *
 ***********************************************************************************************************/

 /*
 First upload to GitHub August 2019 - Please read:
 I created this libray between the end of 2013 and beginning of 2014. I posted it on the Arduino forums
 under another user name (not Felix Hauser). Since then aonther libray for the Sharp IR sensors has been
 published under the same name (SharpIR). In order not to mess up 3rd party projects, I renamed my library
 to SharpAverageIR.


 The Sharp IR sensors are cheap but somehow unreliable. I've found that when doing continous readings to a
 fix object, the distance given oscilates quite a bit from time to time. For example I had an object at
 31 cm. The readings from the sensor were mainly steady at the correct distance but eventually the distance
 given dropped down to 25 cm or even 16 cm. That's quite a bit and for some applications it is quite
 unacceptable. I checked the library http://code.google.com/p/gp2y0a21yk-library/ by Jeroen Doggen
 (jeroendoggen@gmail.com) and what the author was doing is to take a bunch of readings and give an average of them

 This library works similary. It reads a bunch of readings (avg) and then it calculates the average.
 Then it checks every reading to see how much it deviates from the average. If it is out of the
 tolerance given by the user, it is rejected. At the end a new Average Distance is calculated without the
 dismissed values.

 The distance is calculated from a formula extracted from the graphs on the sensors datasheets.
 Since this library takes some measurements before giving a final result, it is not as responsive as
 direct measurements.

 This library has the formulas to work with the GP2Y0A21Y and the GP2Y0A02YK sensors but exanding it for
 other sensors is easy enough.

 Model refenceces:
 use 0 or  1080 on the constructor for the GP2Y0A21Y (from 10 to 80cm)
 use 1 or 20150 on the constructor for the GP2Y0A02Y (from 20 to 150cm)

*/

/*  ****************************     HOW TO USE      *******************

When you initialize the library object on your sketch you have to pass all the above parameters:

 ***  irPin is obviously the pin where the IR sensor is attached
 ***  avg is the number of readings the library does
 ***  tolerance indicates how similar a value has to be from the last value to be taken as valid. It should be a
      value between 0 and 100, like a %. A value of 93 would mean that one value has to be, at least, 93% to the
      previous value to be considered as valid.
 ***  sensorModel is a int to differentiate the two sensor models this library currently supports:
      use 0 or  1080 on the constructor for the GP2Y0A21Y (from 10 to 80cm)
      use 1 or 20150 on the constructor for the GP2Y0A02Y (from 20 to 150cm)

*/

#ifndef SharpAverageIR_h
#define SharpAverageIR_h

#include "Arduino.h"

class SharpAverageIR
{
  public:

    SharpAverageIR (int irPin, int avg, int tolerance, int sensorModel);

    float distance();


  private:

    int cm();

    int _irPin;
    int _model;
    int _avg;
    int _tol;

   int _rawData[];

};

#endif
