// pins
const int RelayControl1 = 2;    // Digital Arduino Pin used to control the motor
const int RelayControl2 = 3;
const int RelayControl3 = 4;
const int RelayControl4 = 5;

const int bmsFaultPin = 7;
const int shutdownPin = 8;

// fun variables
int counter = 1;
int fault = 0;
int RTD = 0;
int sd = 0;
int shut = 0;
int readCounter = 0;

// debounced values from shutdown and bms pins
int shut_down = 0;
int bmsFault = 0;

int debounceCounter = 0;

// shut down debouncing
int shutDown_raw = 0;
int shutCounter = 0;

// bms debouncing
int bmsFault_raw = 0;
int bmsCounter = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(RelayControl1, OUTPUT);
  pinMode(RelayControl2, OUTPUT);
  pinMode(RelayControl3, OUTPUT);
  pinMode(RelayControl4, OUTPUT);

  pinMode(bmsFaultPin, INPUT);
  pinMode(shutdownPin, INPUT);

  digitalWrite(RelayControl1, HIGH);
  digitalWrite(RelayControl2, HIGH);
  digitalWrite(RelayControl3, HIGH);
  digitalWrite(RelayControl4, HIGH);

}

void loop()
{
  bmsFault_raw = digitalRead(bmsFaultPin);
  shutDown_raw = digitalRead(shutdownPin);

  // cheeky debouncing
  if (debounceCounter < 10) {
    debounceCounter++;
    shutCounter += shutDown_raw;
    bmsCounter += bmsFault_raw;
  } else {
    debounceCounter = 0;

    // we need different sensitivity bc obv
    shut_down = shutCounter >= 3;
    bmsFault = bmsCounter >= 5;

    shutCounter = 0;
    bmsCounter = 0;
  }

  Serial.print(shut_down);
  Serial.print(" ");
  Serial.print(bmsFault);
  Serial.print(" ");
  Serial.println(sd);

  // so for the first couple of iterations we only
  // get zero from the pins, so we'll just skip the first 20 iterations
  // e.g. the first 20 pin reads
  if (readCounter < 20) {
    readCounter++;
    return;
  }

  // if we're not getting anything from the shutdown line turn everything off
  if (shut_down == 0)
  {
    sd = 1;
    digitalWrite(RelayControl1, LOW);
    digitalWrite(RelayControl2, HIGH);
    digitalWrite(RelayControl3, HIGH);
    digitalWrite(RelayControl4, HIGH);
  }


  // no issues?
  if (bmsFault == 0 && sd == 0)
  {
    // only run this on start up
    // but after we've checked pins are fine
    if (counter == 1)
    {
      delay(100);
      digitalWrite(RelayControl4, LOW);
      delay(1000);
      digitalWrite(RelayControl3, LOW);
      delay(100);

      counter = 0;
    }

  }
  // oh god oh fuck somethings wrong turn it off turn it off
  else if (bmsFault == 1 || sd == 1)
  {
    digitalWrite(RelayControl1, LOW);
    digitalWrite(RelayControl2, HIGH);
    digitalWrite(RelayControl3, HIGH);
    digitalWrite(RelayControl4, HIGH);
  }
}
