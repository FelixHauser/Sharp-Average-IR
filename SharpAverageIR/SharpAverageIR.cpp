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



#include "Arduino.h"
#include "SharpAverageIR.h"

#define NONDECIMALMULTIPLIER 100

SharpAverageIR::SharpAverageIR(int irPin, int avg, int tolerance, int sensorModel) {

    _irPin=irPin;
    _avg=avg;
    _tol=tolerance;
    _model=sensorModel;

   pinMode (_irPin, INPUT);
   analogReference(DEFAULT);

}


int SharpAverageIR::cm() {

    int raw=analogRead(_irPin);

    float floatRaw=map(raw, 0, 1023, 0, 5000)/1000.0;

    int puntualDistance;

int caseVar;

switch (caseVar) {
  case 0:  //GP2Y0A21Y (from 10 to 80cm)
    puntualDistance=(27.728*pow(floatRaw, -1.2045))*NONDECIMALMULTIPLIER;
    break;
    case 1080:  //GP2Y0A21Y (from 10 to 80cm)  //left for legacy reasons
    puntualDistance=(27.728*pow(floatRaw, -1.2045))*NONDECIMALMULTIPLIER;
    break;
  case 1:  //GP2Y0A02Y (from 20 to 150cm)
    puntualDistance=(61.573*pow(floatRaw, -1.1068))*NONDECIMALMULTIPLIER;
    break;
  case 20150:  //GP2Y0A02Y (from 20 to 150cm)  //left for legacy reasons
    puntualDistance=(61.573*pow(floatRaw, -1.1068))*NONDECIMALMULTIPLIER;
    break;
  default:
    //nothing to show
    break;
}
    return puntualDistance;
}





float SharpAverageIR::distance() {

  //first, an array is populated and the average calculated

   unsigned long summ;

  for (int i=0; i<_avg; i++){

     _rawData[i]=cm();
      summ=summ+_rawData[i];

      }

   summ=summ/_avg;


   //we sort out the values too far from the average


   unsigned long newAverage;
   int averageCounter=0;

   for (int i=0; i<_avg; i++){

     if (_rawData[i]>((_tol/100.0)*summ) && _rawData[i]<((100+(100-_tol))/100.0*summ)){

       newAverage=(newAverage+_rawData[i]);
       averageCounter++;
    }

  }


// we return the new average

return (newAverage*1.0/(averageCounter*NONDECIMALMULTIPLIER));

}
