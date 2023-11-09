void setMediumSpeed(){
  digitalWrite(HighPin, HIGH); 
  digitalWrite(LowPin, HIGH); 
}

void setHighSpeed(){
  digitalWrite(HighPin, LOW);
  digitalWrite(LowPin, HIGH);
}

void setLowSpeed(){
  digitalWrite(LowPin, LOW);
  digitalWrite(HighPin, HIGH);
}

void get_feedback(){
  stateH = digitalRead(stateHpin);
  stateL = digitalRead(stateLpin);
}

bool check_safety(){
  if(stateH == 1){
    if(stateL == 1){
      return 1;
    }
  }
  else{
    return 0;
  }
}

bool check_danger(){
   if(stateH == 0){
    if(stateL == 0){
      return 1;
    }
  }
  else{
    return 0;
  }
}


void shiftToL(){
  if(danger == 0){
    if(safety == 1){
      if(shiftL == 1){
        setLowSpeed();
      }
    }
  }
}

void shiftToM(){
  if(danger == 0){
   if(shiftM == 1){
    setMediumSpeed();
   }
 }
}

void shiftToH(){
  if(danger == 0){
    if(safety == 1){
      setHighSpeed();
    }
  }
}

