#include "Arduino.h"

#define MOTORPIN = 2
#define HUMIDITYSENSOR = A1

int humidity = 0;
int sunlight = 0;
// Number of times per day the pump is switched on
int timesPerDay = 2;
// Number of times per hour the humidity is reported
long reportFreq  = 120;

void setup()
{
	pinMode(2, OUTPUT);
	// Higher reading is drier
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	Serial.begin(9600);
	Serial.println("Starting process");
}

void loop()
{
	// Run the pump variable to how dry the soil is
	// 1 ml/s
	humidity = analogRead(A1);
	int time = 10000 + (20 * (1023 - humidity));
	String time_str = String(time);
	Serial.print("Watering for ");
	Serial.print(time_str);
	Serial.println(" ms");
	digitalWrite(LED_BUILTIN, HIGH);
	digitalWrite(2, HIGH);
	delay(time);
	digitalWrite(LED_BUILTIN, LOW);
	digitalWrite(2, LOW);
	
	// Report the humidity
	for (int i = 0; i < (24 / timesPerDay) * reportFreq; i++)
	{
		humidity = analogRead(A1);
		sunlight = analogRead(A2);
		Serial.print(humidity);
		Serial.print("/");
		Serial.println(sunlight);
		delay(1000L*60L*60L/reportFreq);
	}
}