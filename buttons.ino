void BUTTONS() {
  shift=digitalRead(7);



///////////////////////////////////////////////////sequence select

  if (shift==0&&recordbutton==1){
    prevpot2=pot2;
    if (bouncer1.read()==0 ){ //red
      banko=63;

      bankpr=4;
      bankpg=0;
      bankpb=0;
    }
    if (bouncer4.read()==0){  //yellow
      banko=31;
      bankpr=4;
      bankpg=4;
      bankpb=0;
    }
    if (bouncer2.read()==0 || banko==0){   //blue
      banko=0;
       bankpr=0;
      bankpg=0;
      bankpb=8;
    }
    if (bouncer3.read()==0){//green
      banko=95;
      bankpr=0;
      bankpg=3;
      bankpb=0;
      
    }


    if (bouncertap.read()==LOW){

        play=1;
        ratepot=(analogRead(0));
taptempo=ratepot*10000;
      }
        revbutton = digitalRead(3);
      if (revbutton==0 && prevrevbutton==1){
        playmode++;
        playmode%=2;
    
  }
prevrevbutton=revbutton;
}

  if (shift==1){
 if (bouncer1.fallingEdge()){
      B1_trigger=1;  
    }
    else{
      B1_trigger=0;
    }

 if (bouncer4.fallingEdge()){
      B4_trigger=1; 
    }
    else{
      B4_trigger=0;
    }

 if (bouncer2.fallingEdge()){
      B2_trigger=1; 
    }
    else{
      B2_trigger=0;
    }

 if (bouncer3.fallingEdge()){
      B3_trigger=1; 
    }
    else{
      B3_trigger=0;
    }



  }

  ////////////////////////////////////////////

}



