# Sharp-Average-IR

Arduino Library for Sharp IR Sensors.
See the readme.md file of the master branch (v1.0) for a little bit of background history on this library.

# How it works

The Sharp IR sensors are cheap but somehow unreliable. I've found that when doing continuous readings to a
fix object, the distance given oscillates quite a bit from time to time. For example I had an object at
31 cm. The readings from the sensor were mainly steady at the correct distance but eventually the distance
given dropped down to 25 cm or even 16 cm. That's quite a bit and for some applications it is quite
unacceptable. I checked the library http:code.google.com/p/gp2y0a21yk-library/ by Jeroen Doggen
and what the author was doing is to take a bunch of readings and give an average of them

This library works similarly. It reads a bunch of readings (avg) and then it calculates the average.
Then it checks every reading to see how much it deviates from the average. If it is out of the
tolerance given by the user, it is rejected. At the end a new Average Distance is calculated without the
dismissed values. You might find the concept familiar if you know about statistics and the concept of
standard deviation.

The distance is calculated from a formula extracted from the graphs on the sensors datasheets.
Since this library takes some measurements before giving a final result, it is not as responsive as
direct measurements.

This library has the formulas to work with the GP2Y0A21Y and the GP2Y0A02YK sensors but expanding it for
other sensors is easy enough.

# Setting it up

I won't be explaining how to copy the library into your Arduino IDE, it's well documented...

#### 1. Import Library:
    `<include "SharpAverageIR.h>`

#### 2. Initialize an object:
   `SharpAverageIR sharp(irPin, avg, tolerance, model);`  //I called the object sharp in this example

     **irPin** is the Analog Pin in which the sensor is attached.
     **avg**  is an Int representing the number of measurements it will take.
     **tolerance** is the requested tolerance among values. It is an Int between 1 and 100. Experiment with it.
     **model** it is an Int which represent the sensor in use.
            use **0 or  1080** on the constructor for the GP2Y0A21Y (from 10 to 80cm)
            use **1 or 20150** on the constructor for the GP2Y0A02Y (from 20 to 150cm)

#### 3. Call the public method:
   `float dis=sharp.distance();`  //this method returns a float with the distance.

Please see the example provided on this Library.
