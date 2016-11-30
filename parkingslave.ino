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

}

void loop() {
            if(bicis.available()>0){
              m =bicis.read();
              //Serial.print(m);

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
                  digitalWrite(7, HIGH);
                  delay(4000);
                  digitalWrite(7, LOW);
                }break;
                
                case '2':{
                  digitalWrite(8, HIGH);
                  delay(4000);
                  digitalWrite(8, LOW);
                }break;
                
                case '3':{
                  digitalWrite(9, HIGH);
                  delay(4000);
                  digitalWrite(9, LOW);
                }break;
                
                case '4':{
                  digitalWrite(10, HIGH);
                  delay(4000);
                  digitalWrite(10, LOW);
                }break;

                case '5':{
                  digitalWrite(11, HIGH);
                  delay(4000);
                  digitalWrite(11, LOW);
                }break;

                case '6':{
                  digitalWrite(12, HIGH);
                  delay(4000);
                  digitalWrite(12, LOW);
                }break;                            
            }
            }                                    
}
