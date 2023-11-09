#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// controller pins
#define HighPin 6
#define LowPin 7

// controller feedback pins
#define stateHpin 11
#define stateLpin 12

#define mode_pin 9

bool stateH;
bool stateL;
bool automatic;

// GPS pins
#define RxPin 4
#define TxPin 3

// Speed values 
#define upShiftSpeedL 15   // upshift after 10 km/h onwards
#define upShiftSpeedM  25  // upshift after 25 km/h onwards
#define downShiftSpeedM 10 // downshift to Low when speed is less than 10 km/h
#define downShiftSpeedH 20 // downshift to Medium when speed is less than 20 km/h

// shifiting times
#define upshiftingT 1000
#define downshiftingT 1000

bool shiftL;
bool shiftM;
bool shiftH;

bool danger = 0;
bool safety = 0;

int speed;

unsigned long previousMillisL = 0;
unsigned long previousMillisM = 0;
unsigned long previousMillisH = 0;

TinyGPSPlus gps;
SoftwareSerial mygps(RxPin, TxPin);

void setup(){
  pinMode(HighPin, OUTPUT);
  pinMode(LowPin, OUTPUT);

  pinMode(stateHpin, INPUT_PULLUP);
  pinMode(stateLpin, INPUT_PULLUP);
  pinMode(mode_pin, INPUT_PULLUP);

  setMediumSpeed(); // similar to disabling the relay

  Serial.begin(9600);
  mygps.begin(9600);
  
}

void loop(){
  automatic = digitalRead(mode_pin);
  safety = check_safety();
  danger = check_danger();

  get_feedback();
  getSpeed();
  check_shiftL();
  check_shiftM();
  check_shiftH();

  if(automatic == 0){
    shiftToL();
    shiftToM();
    shiftToH();
  }
  else{
    setMediumSpeed();
  }
   
}


