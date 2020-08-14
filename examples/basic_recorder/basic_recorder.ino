#include <DAQduino.h>

//set up the recorder object.
//DAQduino(int numSamples, int delay_between_samples_in_us)
//delay_between_samples_in_us is a delay in microseconds between samples.
//use this to control how fast the recording is!
DAQduino DAQ = DAQduino(100,1);

//which pin will you use to trigger the recording?
int switchPin = 23;
//which analog pin will be used to record voltages?
int recPin = 8;

//initialize a variable to hold whether we want to be recording or not.
bool recVal = false;


void setup(){
    //prints recorded samples to the serial monitor
    Serial.begin(115200);
    pinMode(recPin,INPUT);//set up the pin of interest as an input.
}

void loop(){
    //read the pin we're using to trigger
    recVal = digitalRead(switchPin);
    //record data if recVal is true
    //argument for record is the analog pin you wish to read
    DAQ.update(recVal,recPin);

}