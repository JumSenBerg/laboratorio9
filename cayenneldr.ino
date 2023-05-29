#include <CayenneMQTTSerial.h>
// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "c0634e00-fcbf-11ed-9ab8-d511caccfe8c";
char password[] = "7922228196b8fad2bc3059e119508f5afd6fe3ce";
char clientID[] = "4f8b0f80-fda8-11ed-9ab8-d511caccfe8c";

#define SENSOR_PIN A0
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

void setup(){
	Cayenne.begin(username, password, clientID);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop()
{
	Cayenne.loop();

}

CAYENNE_OUT(0)
{
	Cayenne.virtualWrite(0, analogRead(SENSOR_PIN), "analog_sensor", "null");
  
}
CAYENNE_IN(1)
{
	if(getValue.asInt()==1){
    digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
    }
}
CAYENNE_IN(2)
{
	if(getValue.asInt()==1){
    digitalWrite(led2, HIGH);
  }else{
    digitalWrite(led2, LOW);
    }
}
CAYENNE_IN(3)
{
	if(getValue.asInt()==1){
    digitalWrite(led3, HIGH);
  }else{
    digitalWrite(led3, LOW);
    }
}
CAYENNE_IN(4)
{
	if(getValue.asInt()==1){
    digitalWrite(led4, HIGH);
  }else{
    digitalWrite(led4, LOW);
    }
}


