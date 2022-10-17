#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
  tmrpcm.speakerPin=9;
  Serial.begin(115200);
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("SD Fail");
    return;
  }
  Serial.println("SD Success");
  tmrpcm.setVolume(5);
  tmrpcm.play("bomdiggy.wav");
}

void loop(){
  if(Serial.available()){    
    if(Serial.read() == 'p'){ //send the letter p over the serial monitor to start playback
      Serial.println("Playing again");
      tmrpcm.play("bomdiggy.wav");
    }
  }
}
