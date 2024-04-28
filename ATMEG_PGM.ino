int led = 7;
int motionSensor = 3;
int motionSensorData;
int relay1 = 14;
int relay2 = 15;
int relay3 = 16;


const int BUTTON_PIN_1 = 4; // Arduino pin connected to button's pin
const int BUTTON_PIN_2 = 5;
const int BUTTON_PIN_3 = 6;

unsigned long TouchButtonpreviousMillis = 0;
long TouchButtoninterval = 8;

unsigned long EspPushpreviousMillis = 0;
long EspPushinterval = 2000;

// variables will change:
int relay1State = LOW;
int relay2State = LOW;
int relay3State = LOW;
//*****1stButton**********
int lastButtonState_1;    // the previous state of button
int currentButtonState_1; // the current state of button
//*****2ndButton**********
int lastButtonState_2;
int currentButtonState_2;
//*****3rdButton**********
int lastButtonState_3;
int currentButtonState_3;



//***********ESP***********
char rec;
//*****************ESP-IoT *************************
String EspPushdata; // complete data, consisting of sensors values

//***********DHT11***************
//#include <dht.h>  // Include library
//#define outPin 13
// Defines pin number to which the sensor is connected


//**************ACS712***************
const int sensorIn = A5;          // pin where the OUT pin from sensor is connected on Arduino
int mVperAmp = 185;           // this the 5A version of the ACS712 -use 100 for 20A Module and 66 for 30A Module
int Watt = 0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

int watt;
void setup() {

  pinMode(led, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  pinMode(motionSensor, INPUT);
  pinMode(BUTTON_PIN_1, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);

  currentButtonState_1 = digitalRead(BUTTON_PIN_1);
  currentButtonState_2 = digitalRead(BUTTON_PIN_2);
  currentButtonState_3 = digitalRead(BUTTON_PIN_3);

  //  Serial2.begin(9600);
  Serial2.begin(9600);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(led, LOW);
  //  delay(500);
  //  digitalWrite(led, HIGH);
  //  delay(500);
  //  digitalWrite(led, LOW);
  //  delay(500);
  //  digitalWrite(led, HIGH);
  //  delay(500);
  //  digitalWrite(led, LOW);
  //  delay(500);
  //  digitalWrite(relay1, HIGH);
  //  delay(500);
  //  digitalWrite(relay1, LOW);
  //  delay(500);
  //  digitalWrite(relay2, HIGH);
  //  delay(500);
  //  digitalWrite(relay2, LOW);
  //  delay(500);
  //  digitalWrite(relay3, HIGH);
  //  delay(500);
  //  digitalWrite(relay3, LOW);
}

void loop() {
  humanDetection();
  CurrentReading();
  TouchButtonRead();
  if (Serial2.available() > 0) {
    rec = Serial2.read();
    if (rec == 'a')
    {
      relayOneOFF();
      digitalWrite(led, HIGH);
    }
    if (rec == 'A')
    {
      relayOneON();
      digitalWrite(led, LOW);
    }
    //***********************AC*****************
    if (rec == 'b')
    {
      relayTwoOFF();
      digitalWrite(led, HIGH);
    }
    if (rec == 'B')
    {
      relayTwoON();
      digitalWrite(led, LOW);
    }

    //***********************AC*****************
    if (rec == 'c')
    {
      relayThreeOFF();
      digitalWrite(led, HIGH);
    }
    if (rec == 'C')
    {
      relayThreeON();
      digitalWrite(led, LOW);
    }
    Serial2.println(rec);
  }
  EspPush();
}


void relayOneON()
{
  digitalWrite(relay1, HIGH);
  relay1State = HIGH;
}

void relayOneOFF()
{
  digitalWrite(relay1, LOW);
  relay1State = LOW;
}
void relayTwoON()
{
  digitalWrite(relay2, HIGH);
  relay2State = HIGH;
}

void relayTwoOFF()
{
  digitalWrite(relay2, LOW);
  relay2State = LOW;
}


void relayThreeON()
{
  digitalWrite(relay3, HIGH);
  relay3State = HIGH;
}

void relayThreeOFF()
{
  digitalWrite(relay3, LOW);
  relay3State = LOW;
}


void humanDetection()
{
  motionSensorData = digitalRead(motionSensor);
  if (motionSensorData == 1)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}


void CurrentReading()
{

  Voltage = getVPP();
  VRMS = (Voltage / 2.0) * 0.707; //root 2 is 0.707
  //  int readValue;
  //  readValue = analogRead(sensorIn);
  //  VRMS = readValue * (5.0/1023.0);
  AmpsRMS = (VRMS * 1000) / mVperAmp;
  Watt = (AmpsRMS * 240 / 1.3);  // 1.3 is an empirical calibration factor
  //  Watt = 240 * VRMS;
  //watt = map(AcsValueF, 0, -50000, 0,50000);
  //  if (Watt < 40)
  //  {
  //    Watt = 0;
  //  }
}
float getVPP()
{
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 1023;          // store min value here

  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) //sample for 1 Sec
  {
    readValue = analogRead(sensorIn);
    // see if you have a new maxValue
    if (readValue > maxValue)
    {
      /*record the maximum sensor value*/
      maxValue = readValue;
    }
    if (readValue < minValue)
    {
      /*record the minimum sensor value*/
      minValue = readValue;
    }
  }

  //  Subtract min from max
  result = ((maxValue - minValue) * 5.0) / 1023.0;
  // result = readValue * (5.0/1023.0);
  return result;
}

void TouchButtonRead()
{
  unsigned long currentMillis = millis();

  if (currentMillis - TouchButtonpreviousMillis >= TouchButtoninterval) {
    TouchButtonpreviousMillis = currentMillis;

    lastButtonState_1    = currentButtonState_1;      // save the last state
    currentButtonState_1 = digitalRead(BUTTON_PIN_1); // read new state

    if (lastButtonState_1 == HIGH && currentButtonState_1 == LOW)
    {
      // Serial.println(" button 1 pressed");
      // toggle state of LED
      relay1State = !relay1State;
      // control LED arccoding to the toggled state
      digitalWrite(relay1, relay1State);
    }

    lastButtonState_2    = currentButtonState_2;      // save the last state
    currentButtonState_2 = digitalRead(BUTTON_PIN_2); // read new state

    if (lastButtonState_2 == HIGH && currentButtonState_2 == LOW)
    {
      // Serial.println(" button 1 pressed");
      // toggle state of LED
      relay2State = !relay2State;
      // control LED arccoding to the toggled state
      digitalWrite(relay2, relay2State);
    }

    lastButtonState_3    = currentButtonState_3;      // save the last state
    currentButtonState_3 = digitalRead(BUTTON_PIN_3); // read new state

    if (lastButtonState_3 == HIGH && currentButtonState_3 == LOW)
    {
      // Serial.println(" button 1 pressed");
      // toggle state of LED
      relay3State = !relay3State;
      // control LED arccoding to the toggled state
      digitalWrite(relay3, relay3State);
    }
  }
}
void EspPush()
{
  unsigned long EspCurrentMillis = millis();
  if (EspCurrentMillis - EspPushpreviousMillis >= EspPushinterval) {
    EspPushpreviousMillis = EspCurrentMillis;
    EspPushdata = EspPushdata + Watt + "," + AmpsRMS + "," + motionSensorData + "," + relay1State + "," + relay2State + "," + relay3State; // comma will be used a delimeter
    Serial2.println(EspPushdata);
    EspPushdata = "";
  }
}
