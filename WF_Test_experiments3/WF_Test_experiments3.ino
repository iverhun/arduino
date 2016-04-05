/*
   YF-S201 Hall Effect Water Flow Meter / Sensor
   http://www.hobbytronics.co.uk/yf-s201-water-flow-meter
   
   Read Water Flow Meter and output reading in litres/hour

*/

volatile unsigned long  flow_frequency;  // Measures flow meter pulses
unsigned int  l_min;          // Calculated litres/hour                      
unsigned char flowmeter = 2;  // Flow Meter Pin number
unsigned long currentTime;
unsigned long cloopTime;

float mililitres = 0;

void flow ()                  // Interruot function
{ 
   flow_frequency++;
} 

void setup()
{ 
   pinMode(flowmeter, INPUT);
   Serial.begin(9600); 
   attachInterrupt(0, flow, RISING); // Setup Interrupt 
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
      cloopTime = currentTime;              // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. (Results in +/- 3% range)
      // l_min = (flow_frequency  / 73.0); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour 
      //flow_frequency = 0;                   // Reset Counter
      //Serial.print(l_min, 5);            // Print litres/hour
      //Serial.println(" L/min");
      // Serial.println(flow_frequency, DEC);
      //Serial.println(" pulses");

      //====
      mililitres = flow_frequency/3.19488;
      Serial.print(mililitres, DEC);
      Serial.println(" ml");
      // mililitres_per_sec =  
   }
}

