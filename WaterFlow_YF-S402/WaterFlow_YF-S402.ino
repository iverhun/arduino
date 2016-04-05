/*
KY-003 Hall magnetic switch
*/
 
int Led = 13 ; // define LED Interface
int SENSOR = 0 ; // define the Hall magnetic sensor interface
int val1 ; // define numeric variables val
 
void setup ()
{
  pinMode (Led, OUTPUT) ;    // define LED as output interface
  pinMode (SENSOR, INPUT) ;  // define the Hall magnetic sensor line as input
  Serial.begin(9600);           // set up Serial library at 9600 bps
}
 
void loop ()
{
  val1 = analogRead (SENSOR) ; // read sensor line
  Serial.println(val1 * 100 /1024) ;
  delay(1000) ;
}
