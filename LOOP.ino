unsigned long recordoffsettimer,offsetamount,taptempof;
byte hello;


void loop() {
bouncertap.update ( );
bouncer1.update ( );
bouncer2.update ( );
bouncer4.update ( );
bouncer3.update ( );
  LEDS();
  BUTTONS();
  RECORD();

 // dd++;
 // if (dd==0){
//pot1=analogRead(1);
//  pot1=12;
//  pot2=256;
//pot2=(analogRead(0));
pot1=((analogRead(1))>>1)+115;
pot2=((analogRead(0))>>2)+145;
 
 trigger_in_read=digitalRead(16);
 
 if (trigger_in_read==1 && prev_trigger_in_read==0){
   trigger_input=1;
 }
   else{
     trigger_input=0;
 
   }
  prev_trigger_in_read=trigger_in_read;
  
  eigth=loopstep%4;
  
  if(eigth==0){
   digitalWrite(12, HIGH);
  // tl++;
    }
    else{
       digitalWrite(12, LOW);
 }
    /*
   if (tl>3){
    trigger_out_latch=0;
   digitalWrite(12, LOW);
   tl=0l;
  }
   */
 
 
//  }
//  dd%=4;
  
 // cc++;

//Serial.print(B3_latch);    Serial.print("  "); 
//Serial.print(B1_latch);    Serial.print("  "); 
//Serial.print(pot1);    Serial.print(","); 
//Serial.println(taptempo);

  ////////////////////////////////////////////

taptempof=taptempo;

 recordoffsettimer=micros()-prev ;
    offsetamount=taptempof-(taptempof>>2 );
 //  offsetamount=0;
//prev=micros();
   if ((recordoffsettimer)>(offsetamount))
{

        loopstepf=loopstep+1;
     loopstepf%=32;

}

  if (play==1){
    
    if (onetime==1){
      taptempo=5000000;
onetime=0;
    }
    else{
    prevloopstep=loopstep;
    preva=eigth;
    
    if (recordmode==1){
    if (micros() - prev > (taptempof) ) {
     // trigger_out_latch=1;
      prev = micros();    
      //  ledstep=(loopstep%8); 
      loopstep++;
      loopstep%=32;
      
  //   half=loopstep%16;
  //   eigth=loopstep%4;
    }

    }
  }

    


    B4_loop_trigger=B4_sequence[loopstep+banko];
    B1_loop_trigger=B1_sequence[loopstep+banko];
    B2_loop_trigger=B2_sequence[loopstep+banko];
    B3_loop_trigger=B3_sequence[loopstep+banko];
  }

  if (play==0){
    loopstep=0;
    prev==0;
    B4_loop_trigger=0;
    B1_loop_trigger=0;
    B2_loop_trigger=0;
    B3_loop_trigger=0;

  }

  if (loopstep!=prevloopstep && B3_loop_trigger==1){

    B3_seq_trigger=1;
    //freq3=kickfreqsequence[loopstepf];
  }
  else {
    B3_seq_trigger=0;
  }

  if (loopstep!=prevloopstep && B2_loop_trigger==1){

    B2_seq_trigger=1;
    //freq3=kickfreqsequence[loopstepf];
  }
  else {
    B2_seq_trigger=0;
  }

  if (loopstep!=prevloopstep && B4_loop_trigger==1){

    B4_seq_trigger=1;
    //freq3=kickfreqsequence[loopstepf];
  }
  else {
    B4_seq_trigger=0;
  }

  if (loopstep!=prevloopstep && B1_loop_trigger==1){

    B1_seq_trigger=1;
  }
  else {
    B1_seq_trigger=0;
  }
  
  
  
    if (B3_trigger==1 || B3_seq_trigger==1){
    index3=0;
    accumulator3=0;
    B3_latch=1;
  }

  if (B4_trigger==1 || B4_seq_trigger==1){
    index4=0;
    accumulator4=0;
    B4_latch=1;
  }
  if (B1_trigger==1){
    index=0;
    accumulator=0;
    B1_latch=1;
  }

  if (B1_seq_trigger==1){
    index_freq_1=0;
    accu_freq_1=0;
    B1_seq_latch=1;
  }
  if (B2_seq_trigger==1){
    index_freq_2=0;
    accu_freq_2=0;
    B2_seq_latch=1;
  }

  if (B2_trigger==1){
    index2=0;
    accumulator2=0;
    B2_latch=1;
  }

  
  
  
  
  //////////////////////////////////////////////////////////////// T A P

//what=digitalRead(16);
 // tapbutton = digitalRead(18);

 if (shift==1){
   
 if (bouncertap.fallingEdge()|| trigger_input==1){
 //  if (what==0 && pwhat==1){
t++;
   t%=2;
    tapbank[t]=((micros())-prevtap)>>2;
   taptempo=((tapbank[0]+tapbank[1])>>1);
// taptempo=((micros())-prevtap)>>2;
    prevtap=micros();
 //   loopstep=31;
   // prev=0;
  }
  else{
     }
 // ptapbutton= tapbutton;
 // pwhat=what;
 }

 
}





