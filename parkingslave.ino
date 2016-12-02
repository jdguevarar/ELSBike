#include<SoftwareSerial.h>


SoftwareSerial bicis(2,3);//RX:PIN2-TX:PIN3
char m='0';
int nbics[]={1,1,1,1,1,0};
int i=0;
char c[sizeof(nbics)/sizeof(int)];


void setup() {
  Serial.begin(9600);
  bicis.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);


}

void loop() {
            if(bicis.available()>0){
              m =bicis.read();     

              switch (m){

                case '0':{
                    //char c[sizeof(nbics)/sizeof(int)];  
                    while(i<=(sizeof(c)-1)){
                      c[i]=digitalRead(i+14) +'0';
                      bicis.write(c[i]);
                      delay(200);   
                      i++;
                    }
                    i=0;
                }break;
  
                case '1':{
                    if(digitalRead(7)==LOW) digitalWrite(7, HIGH);
                    else if(digitalRead(7)==HIGH) digitalWrite(7, LOW);
                  }break;
                  
                  case '2':{
                    if(digitalRead(8)==LOW) digitalWrite(8, HIGH);
                    else if(digitalRead(8)==HIGH) digitalWrite(8, LOW);                
                  }break;
                  
                  case '3':{
                    if(digitalRead(9)==LOW) digitalWrite(9, HIGH);
                    else if(digitalRead(9)==HIGH) digitalWrite(9, LOW);
                  }break;
                  
                  case '4':{
                    if(digitalRead(10)==LOW) digitalWrite(10, HIGH);
                    else if(digitalRead(10)==HIGH) digitalWrite(10, LOW);                  
                  }break;
  
                  case '5':{
                    if(digitalRead(11)==LOW) digitalWrite(11, HIGH);
                    else if(digitalRead(11)==HIGH) digitalWrite(11, LOW);                  
                  }break;
  
                  case '6':{
                   if(digitalRead(12)==LOW) digitalWrite(12, HIGH);
                    else if(digitalRead(12)==HIGH) digitalWrite(12, LOW);                  
                  }break;                            
              }
            }                        
}
