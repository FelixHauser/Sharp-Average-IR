#Sharp-Average-IR
 Arduino Library for Sharp IR Sensors.

#History
I posted this library for the first time on the Arduino forums on 07 January 2014 under another alias (not Felix Hauser) and with the name **SharpIR**. It was a simple link to the files, saved on my public folder on Dropbox. Since it was not very visible, with time another library has been published with the same name and available directly from the Arduino-IDE. Do not be confused, both libraries work very differently.
I hope that, by posting it again on GitHub under another name, it won't be confusing by users.

#How it works

The Sharp IR sensors are cheap but somehow unreliable. I've found that when doing continuous readings to a
fix object, the distance given oscillates quite a bit from time to time. For example I had an object at
31 cm. The readings from the sensor were mainly steady at the correct distance but eventually the distance
given dropped down to 25 cm or even 16 cm. That's quite a bit and for some applications it is quite
unacceptable. I checked the library http:code.google.com/p/gp2y0a21yk-library/ by Jeroen Doggen
(jeroendoggen@gmail.com) and what the author was doing is to take a bunch of readings and give an average of them

The present library works similarly. It reads a bunch of readings (avg), it checks if the current reading
differs a lot from the previous one (tolerance) and if it doesn't differ a lot, it takes it into account
for the mean distance.
The distance is calculated from a formula extracted from the graphs on the sensors datasheets.
Since this library takes some measurements before giving a final result, it is not as responsive as
direct measurements.
This library has the formulas to work with the GP2Y0A21Y and the GP2Y0A02YK sensors but expanding it for
other sensors is easy enough.

#Setting it up

I recommend to see the example file on the library.
It works similar to other libraries: Setting up and object, setting the parameters and done.
