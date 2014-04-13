ISR(TIMER2_COMPA_vect) {
  OCR2A = 50;


    if (playmode==0){ //reverse
  snare_sample = (pgm_read_byte(&snare_table[(indexr)]))-128;
  kick_sample = (pgm_read_byte(&kick_table[(index2r)]))-128;
  hat_sample = (pgm_read_byte(&tom_table[(index3r)]))-128;
  bass_sample = (((pgm_read_byte(&bass_table[(index4r)]))))-128;

  B1_freq_sample = pgm_read_byte(&tom_table[(index2vr)])-128;
  B2_freq_sample = (pgm_read_byte(&bass_table[(index4vr)]))-128;
    }
if (playmode==1){
  snare_sample = (pgm_read_byte(&snare_table[(index3)]))-128;
  kick_sample = (pgm_read_byte(&kick_table[(index4)]))-128;
  hat_sample = (pgm_read_byte(&tom_table[(index)]))-128;
  bass_sample = (((pgm_read_byte(&bass_table[(index2)]))))-128;

  B1_freq_sample = pgm_read_byte(&tom_table[(index_freq_1)])-128;
  B2_freq_sample = (pgm_read_byte(&bass_table[(index_freq_2)]))-128;
}


sample= ((snare_sample+kick_sample+hat_sample+bass_sample+B1_freq_sample+B2_freq_sample)+128);
  byte sample_out=constrain(sample,0,255);


   dac.output(sample_out);

  ///////////////////////////////////////////////////////////////////////////////

  if (playmode==0){
    indexr=(index3-snare_length)*-1;
    index2r=(index4-kick_length)*-1;   
    index3r=(index-tom_length)*-1;
    index4r=(index2-bass_length)*-1;
    index2vr=(index_freq_1-tom_length)*-1;
    index4vr=(index_freq_2-bass_length)*-1;

  }
  
  if (B1_latch==1){
    accumulator += pot1;
    index=(accumulator >> (6));  
    if (index>tom_length){

      index=0;
      accumulator=0;
      B1_latch=0;
    }
  }

  if (B2_latch==1){
    accumulator2 += (pot2);
    index2=(accumulator2 >> (6));  
    if (index2>bass_length){

      index2=0;
      accumulator2=0;
      B2_latch=0;
    }
  }

  if (B3_latch==1){
    accumulator3 += (85);
    index3=(accumulator3 >> 6);  
    if (index3>snare_length){

      index3=0;
      accumulator3=0;
      B3_latch=0;
    }
  }

  if (B4_latch==1){
    accumulator4 += (130);
   // index4b=(accumulator4 >> (6));  
    index4=(accumulator4 >> (6));
    if (index4>kick_length){

      index4=0;
      accumulator4=0;
      B4_latch=0;
    }
  }

  accu_freq_1 += kf;
  index_freq_1=(accu_freq_1 >> (6));  
  if (B1_seq_trigger==1){
    kf=B1_freq_sequence[loopstepf+banko];
    kfe=kf;
  }

  if (index_freq_1>tom_length){
    kf=0;
    index_freq_1=0;
    accu_freq_1=0;
    B1_seq_latch=0;
  }


  accu_freq_2 += pf;
  index_freq_2=(accu_freq_2 >> (6));

  if (B2_seq_trigger==1){
    pf=B2_freq_sequence[loopstepf+banko];
  }
  if (index_freq_2>bass_length){
    pf=0;
    index_freq_2=0;
    accu_freq_2=0;
    B2_seq_latch=0;
  }


}



