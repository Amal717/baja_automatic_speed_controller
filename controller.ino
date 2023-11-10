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
  if(danger == 0){  // if there is no problem
    if(safety == 1){ // if speed is in medium
      if(shiftL == 1){ // if its time to shift to Low speed
        L=1;//setLowSpeed();  // here the safety and SetLowSpeed() contradicts, 
        M=0;                  // so if there is safety then store that its safe
        H=0;                  // and store that store L can be on
      }
    }
  }
}

void shiftToM(){
  if(danger == 0){
   if(shiftM == 1){
    M=1;//setMediumSpeed();
    L=0;
    H=0;
   }
 }
}

void shiftToH(){
  if(danger == 0){
    if(safety == 1){
      if(shiftH == 1){
      H=1;//setHighSpeed();
      M=0;
      L=0;
     }
   }
  }
} 

void control_speed(){
  if(L == 1){
    setLowSpeed();
  }
  else if(M == 1){
    setMediumSpeed();
  }
  else if(H == 1){
    setHighSpeed();
  }
}
