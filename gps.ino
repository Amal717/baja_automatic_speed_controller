void printGps(){
  if(gps.location.isUpdated()){
    Serial.print("Lattitude=");
    Serial.print(gps.location.lat(),6);
    Serial.print("Longitude=");
    Serial.println(gps.location.lng(),6);
  }
}

void getSpeed(){
  if(mygps.available()){
    gps.encode(mygps.read());
    if(gps.location.isValid()){
      speed = gps.speed.kmph();
    }
  }
}




void check_shiftL(){
  if(speed <= upShiftSpeedL){   // check if speed is less than the upshiftSpeedL 15
    if(millis() - previousMillisL >= downshiftingT){  // check if downshifting time has passed
        previousMillisL = millis();
        if(speed <= downShiftSpeedM){ // check if the speed has further reduced 10
          shiftL = 1;
          shiftM = 0;
          shiftH = 0;
        }
    }
  }
  else{
    shiftL = 0;
  }
}




void check_shiftM(){
  if(speed >= upShiftSpeedL){  // check if speed is greater than the upshiftSpeedL 15
    if(millis() - previousMillisM >= upshiftingT){ // check if upshifting time has passed
      previousMillisM = millis();
      if(speed >= upShiftSpeedL){ // check if the speed is stedy or increasing >= 15
        shiftM = 1;
        shiftL = 0;
        shiftH = 0;
      }
    }
  }
  else{
    shiftM = 0;
  }

  if(speed <= upShiftSpeedM){ // check if speed is less than downshiftspeedH 25
    if(millis() - previousMillisH >= downshiftingT){ // check is downshifting time has passed
      previousMillisH = millis();
      if(speed <= downShiftSpeedH){  // check if speed is further reduced, less than 20
        shiftM = 1;
        shiftL = 0;
        shiftH = 0;
      }
    }
  }
  else{
    shiftM = 0;
  }
}


void check_shiftH(){
  if(speed >= upShiftSpeedM){ // check if speed is greater than upshiftspeedM 25
    if(millis() - previousMillisH >= upshiftingT){ // check if upshifting time has passed
      previousMillisH = millis();
      if(speed >= upShiftSpeedM){ // check if speed is steady or increasing, greater than 25
        shiftH = 1;
        shiftM = 0;
        shiftL = 0;
      }
    }
  }
  else{
    shiftH = 0;
  }
}





