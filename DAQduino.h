/*
High speed data acquisition for arduino
Alexander Brown
August 2020

*/

#ifndef DAQduino_h
#define DAQduino_h

#include "Arduino.h"


class DAQduino
{
public:
    DAQduino(int insamples, int inusdelay);
    void record(int pin);
    void printData(bool printTimes);
    void clearData();
    int vals[500];
    unsigned long times[500];
    bool haveData;
    int samples;
    int usdelay;


};



#endif