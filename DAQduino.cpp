/*
High speed data acquisition for arduino
Alexander Brown
August 2020

*/

#include "DAQduino.h"

DAQduino::DAQduino(int insamples, int inusdelay){
    if(insamples<=500){
        samples = insamples;
    }
    else{
        samples = 500;
    }
    usdelay = inusdelay;
    haveData = false;
}

void DAQduino::update(bool rec, int pin){
    if(rec&&!oldrec){
        if(!haveData){
            haveData = true;
            for(int k = 0; k<samples; k++){
                vals[k] = analogRead(pin);
                times[k] = micros();
                delayMicroseconds(usdelay);
            }
        }
        printData(true);
        clearData();
    }
    oldrec = rec;
}

void DAQduino::printData(bool printTimes){
    if(haveData){
        if(printTimes){
            for(int k = 0; k<samples; k++){
                Serial.print(times[k]);
                Serial.print("\t");
                Serial.print(vals[k]);
                Serial.println();
            }
        }
        else{
            for(int k = 0; k<samples; k++){
                Serial.print(vals[k]);
                Serial.println();
            }
        }
    }
    else{
        Serial.println("No Data to Show!");
    }

}

void DAQduino::clearData(){
    haveData = false;
    for(int k = 0; k<samples; k++){
            vals[k] = 0;
            times[k] = 0;
    }
}

