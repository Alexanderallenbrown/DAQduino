#include <DAQduino.h>

/*
This demonstrates the DAQduino class
*/


//set up the recorder object.
//DAQduino(int numSamples, int delay_between_samples_in_us)
DAQduino DAQ = DAQduino(100,1);
//these take up a lot of memory, so probably only can have 1 per sketch!

//which pin will you use to trigger the recording?
int recPin = 23;
//detect a rising edge on this pin
bool recVal = false;
bool oldrecVal = false;
//which pin will you use to clear the data in the buffer?
int clearPin = 29;


void setup(){
    //prints recorded samples to the serial monitor
    Serial.begin(115200);
}

void loop(){
    //read the pin we're using to trigger
    recVal = digitalRead(recPin);

    //record if there's a rising edge.
    //in an experiment, you'd want to set your outputs
    //right after this rising edge, THEN call DAQ.record()
    //because DAQ.record() is blocking, meaning
    //no other code will run until all samples have been collected.
    if(recVal&&!oldrecVal){
        //argument for record is the analog pin you wish to read
        DAQ.record(8);
        //the argument for printData is whether to print times AND values, or just vales.
        DAQ.printData(true);
    }
    //clear the data buffer if button A is pressed on the ME480 rig.
    if(!digitalRead(clearPin)){
        DAQ.clearData();
    }

    oldrecVal = recVal;


}