void LEDS() {
  analogWrite(9,bout>>1); //Blue
  analogWrite(6,gout>>1); //green
  analogWrite(5,rout>>1);



  preveigth=eigth;

  if (erase==1){
    e=16;
  }
  if (erase==0){
    e=0;
  }

  if (g>1){ 
    g--;
  }
  if(g<=1){ 
    g=0;
  }

  if (r>1){ 
    r--;
  }
  if(r<=1){ 
    r=0;
  }

  if (b>1){ 
    b--;
  }
  if(b<=1){ 
    b=0;
  }

  if (record==0 && play==0){



    rout=16;
    gout=16;
    bout=16;
  }




  if (play==1 && record ==0){
    bout=b;
    rout=r;
    gout=g;


    ///////////////////////////////////////////////////CHANGE TO ONLY += WHEN LOOPSTEP != PREVLOOPSTEP

    if( loopstep==0 && prevloopstep==1 ){
      r=64;
      g=64;
      b=64;

    }
    /*
    else  if( loopstep==16 ){
      r=4;
      g=64;
      b=4;
    }
*/
    else if( loopstep%4 ==0 && prevloopstep%4!=0 ){
      r+=64;
      g+=64;
      b+=64;

    }
    else {
      b=bankpb;
      r=bankpr;
      g=bankpg;
    }
    
    
  }

  if (play==1 && record==1){
    bout=b;
    rout=r;
    gout=g;

    if( loopstep==0 ){
      r=32;
      g=16;
      b=6;
    }
    else  if( loopstep==16 ){
      r=32;
      g=0;
      b=0;
    }

    else if( loopstep==4 || loopstep==8 || loopstep==12   || loopstep==20 || loopstep==24 || loopstep==28){
      r=48;
      g=0;
      b=0;
    }
    else {
     b=bankpb;
     r=bankpr;
     g=bankpg;
    }


  }
}

/*
  r+=2;
 g++;
 b+=7;
 analogWrite(9,g);100
 analogWrite(6,b);100
 analogWrite(5,r); 150ohm
 
 if (play==1 && record==1){
 if (measure==0 && prevloopstep!=loopstep){
 beat==1;
 analogWrite(9,225);
 analogWrite(5,225);
 analogWrite(6,225);
 }
 
 
 if (half==0 && prevloopstep!=loopstep){
 beat==1;
 analogWrite(5,32);
 }
 
 else {
 analogWrite(9,0);
 analogWrite(5,1);
 analogWrite(6,0);
 beat==0;
 }
 }
 
 
 */








