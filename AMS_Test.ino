// LICENCSE - THIS CODE IS LICENSED TO CALVIN JOHNSON AS HIS IP AND CEEBS TO WRITE THE REST THX

int RelayControl1 = 2;    // Digital Arduino Pin used to control the motor
int RelayControl2 = 3;
int RelayControl3 = 4;
int RelayControl4 = 5;
int counter = 1;
int fault = 0;
int RTD = 0;
int sd = 0;
int shut = 0;
 
 
void setup()
{
  Serial.begin(9600);
  pinMode(RelayControl1, OUTPUT);
  pinMode(RelayControl2, OUTPUT);
  pinMode(RelayControl3, OUTPUT);
  pinMode(RelayControl4, OUTPUT);
  digitalWrite(RelayControl1,HIGH);
  digitalWrite(RelayControl2,HIGH);
  digitalWrite(RelayControl3,HIGH);
  digitalWrite(RelayControl4,HIGH); 
    
}
 
 
void loop()
{
  shut = analogRead(A4);
  float shut_voltage = shut * (5.0 / 1023.0);
  if(shut_voltage < 500)
  {
    sd = 1;
    digitalWrite(RelayControl1,HIGH);
    digitalWrite(RelayControl2,HIGH);
    digitalWrite(RelayControl3,HIGH);
    digitalWrite(RelayControl4,HIGH); 
    exit(0);
  }
  else if(shut > 500)
  {
     sd = 0;
  }
  fault = analogRead(A0);
  float voltage = fault * (5.0 / 1023.0);
  if(fault < 200 && sd == 0)
  {
    while(counter == 1)
    {
      delay(100);
      digitalWrite(RelayControl4,LOW);
      delay(1000);
      digitalWrite(RelayControl3,LOW);
      delay(100);
         
      counter++;
    }
    
  }
  else if(fault >= 400)
  {
    digitalWrite(RelayControl1,HIGH);
    digitalWrite(RelayControl2,HIGH);
    digitalWrite(RelayControl3,HIGH);
    digitalWrite(RelayControl4,HIGH);
  }
   
}
