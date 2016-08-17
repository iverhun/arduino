// #include <Notes.h>
#include <Pitches.h>

/*
   YF-S201 Hall Effect Water Flow Meter / Sensor
   http://www.hobbytronics.co.uk/yf-s201-water-flow-meter
   
   Read Water Flow Meter and output reading in litres/hour

*/

// # include "BurreMelody.h"

notes notes;

volatile unsigned long  pulses_count;  // Measures flow meter pulses_count
unsigned int  l_min;          // Calculated litres/hour                      
unsigned char flowmeter = 2;  // Flow Meter Pin number

unsigned long previousTime;
unsigned long currentTime;
unsigned long cloopTime;


//boolean flowing = false;
int previous_pulses_count = 0;
int pulses_per_second = 0;
unsigned long noflow_sec = 0;
unsigned long last_pulse_time = 0;

unsigned int millilitres_per_sec = 0;

float mililitres = 0;

void flow ()                  // Interrupt function
{ 
   pulses_count++;
   last_pulse_time = millis();
} 

void setup()
{ 
   pinMode(flowmeter, INPUT);
   Serial.begin(9600); 
   attachInterrupt(digitalPinToInterrupt(2), flow, RISING); // Setup Interrupt 
                                     // see http://arduino.cc/en/Reference/attachInterrupt
   sei();                            // Enable interrupts  
   currentTime = millis();
   cloopTime = currentTime;
} 

void loop ()    
{
   currentTime = millis();

   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 1000))
   {     
      timeDelta = currentTime - cloopTime;

      current_pulses_count = pulses_count; // since the interrupts are not disabled, the pulses_count may change      
      mililitres = current_pulses_count/3.19488;

      pulsesDelta = current_pulses_count - previous_pulses_count;
      millilitres_per_sec = pulsesDelta/3.19488;

      Serial.print(pulses_count, DEC);
      Serial.print(" pulses - ");
      Serial.print(mililitres, DEC);
      Serial.print(" ml;\t");

      Serial.print("noflow: ");
      Serial.print(noflow_sec, DEC);
      Serial.print(" s;\t");

      Serial.print("ml/s: ");
      Serial.println(millilitres_per_sec, DEC);

      
//      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour 

      noflow_sec = (millis() - last_pulse_time)/1000;
      if (mililitres > 100 && millilitres_per_sec > 0) {
          // notes.playNotes(melody, noteDurations);
          // tone(8, 440, 200);
          // TODO: turn on pin 13
      } 

      if (noflow_sec > 5) {
        noTone(8);
        // TODO: turn off pin 13

        // reset counters
        pulses_count = 0;
        millilitres_per_sec = 0;
        previous_pulses_count = 0;
      }

      // reset al variables
      previous_pulses_count = current_pulses_count;
      cloopTime = currentTime;              // Updates cloopTime
      previousTime = currentTime;
   }
}

      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. (Results in +/- 3% range)
      // l_min = (flow_frequency  / 73.0); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour 
      //flow_frequency = 0;                   // Reset Counter
      //Serial.print(l_min, 5);            // Print litres/hour
      //Serial.println(" L/min");
      // Serial.println(flow_frequency, DEC);
      //Serial.println(" pulses");

