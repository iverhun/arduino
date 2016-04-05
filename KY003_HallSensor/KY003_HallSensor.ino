/*
KY-003 Hall magnetic switch
*/
 
int Led = 13 ; // define LED Interface
int SENSOR_1 = 5 ; // define the Hall magnetic sensor interface
int SENSOR_2 = 10 ; // define the Hall magnetic sensor interface
int val1 ; // define numeric variables val
int val2 ; // define numeric variables val
int counter = 0 ; // define numeric variables val
 
void setup ()
{
  pinMode (Led, OUTPUT) ;    // define LED as output interface
  pinMode (SENSOR_1, INPUT) ;  // define the Hall magnetic sensor line as input
  pinMode (SENSOR_2, INPUT) ;  // define the Hall magnetic sensor line as input
  Serial.begin(9600);           // set up Serial library at 9600 bps
}
 
void loop ()
{
  val1 = digitalRead (SENSOR_1) ; // read sensor line
  if (val1 == LOW) // when the Hall sensor detects a magnetic field, Arduino LED lights up
  {
    digitalWrite (Led, HIGH);
    counter = counter + 1;
    String message = "Counter: ";
    Serial.println(message + counter) ;
  }

//  val2 = digitalRead (SENSOR_2) ; // read sensor line
//  if (val2 == LOW) // when the Hall sensor detects a magnetic field, Arduino LED lights up
  {
    digitalWrite (Led, LOW);
    //counter = counter + 1;
    String message = "Counter: ";
    //Serial.println(message + counter) ;
  }
}
