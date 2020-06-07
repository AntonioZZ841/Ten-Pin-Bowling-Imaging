#include<SPI.h>                   
#include<RF24.h>                  


RF24 radio(9, 10) ; 
void setup(void) {
  Serial.begin(9600);
  radio.begin();        
  radio.setPALevel(RF24_PA_MAX) ;
  radio.setChannel(0x60) ;           
  radio.openReadingPipe(1,0xF0F0F0F0E1LL) ;  
  radio.enableDynamicPayloads() ;
  radio.startListening();
  

}

void loop(void) {
  
  char text[10]= "";
  Serial.println("Searching");
  delay(10);
  if (radio.available()){
    Serial.println("Found something");
    radio.read(&text,sizeof(text));
    Serial.println(text);
  }
  
  delay(100);

}
