#include "SharpAverageIR.h"

#define ir A0
#define model 0

boolean done=false;


SharpAverageIR sharp(ir, 25, 95, model);

/*  ****************************     HOW TO USE      *******************

1- Import Library:

    <include "SharpAverageIR.h>

2- Initialize an object:

   SharpAverageIR sharp(ir, 25, 95, model);



When you initialize the library object on your sketch you have to pass all the above parameters:

 ***  irPin is obviously the pin where the IR sensor is attached
 ***  avg is the number of readings the library does
 ***  tolerance indicates how similar a value has to be from the last value to be taken as valid. It should be a
      value between 0 and 100, like a %. Given a tolerance of 95% means that all the values have to be within a 5%
      margin of error.
 ***  sensorModel is a int to differentiate the two sensor models this library currently supports:
      use 0 or  1080 on the constructor for the GP2Y0A21Y (from 10 to 80cm)
      use 1 or 20150 on the constructor for the GP2Y0A02Y (from 20 to 150cm)


3- Call the public method:

   float dis=sharp.distance();

   this method returns a float with the distance.


*/



void setup(){

  Serial.begin(9600);


}





void loop(){

  delay(1000);    // it gives you time to open the serial monitor after you upload the sketch

 if (done==false){  // it only runs the loop once


  unsigned long pepe1=millis();  // takes the time before the loop on the library begins

  float dis=sharp.distance();  // this returns the distance to the object you're measuring




  Serial.print("Average distance: ");  // returns it to the serial monitor
  Serial.println(dis);

  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
  Serial.print("Time taken (ms): ");
  Serial.println(pepe2);


done=true;

}

}
