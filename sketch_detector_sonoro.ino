// these constants won't change:
const int analogPin = A0; // the pin that the potentiometer is attached to
const int ledCount = 10;  // the number of LEDs in the bar graph

int ledPins[] = {
    4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // an array of pin numbers to which LEDs are attached

void setup()
{
    Serial.begin(9600);

    // loop over the pin array and set them all to output:
    for (int thisLed = 0; thisLed < ledCount; thisLed++)
    {
        pinMode(ledPins[thisLed], OUTPUT);
    }
}

void loop()
{
    // read the potentiometer:
    int sensorReading = analogRead(analogPin);
    Serial.println(sensorReading);
    // map the result to a range from 0 to the number of LEDs:
    int ledLevel = map(sensorReading, 39, 150, 0, ledCount);

    // Serial.println(ledLevel);

    // loop over the LED array:
    for (int thisLed = 0; thisLed < ledCount; thisLed++)
    {
        // if the array element's index is less than ledLevel,
        // turn the pin for this element on:
        if (thisLed < ledLevel)
        {
            digitalWrite(ledPins[thisLed], HIGH);
        }
        // turn off all pins higher than the ledLevel:
        else
        {
            digitalWrite(ledPins[thisLed], LOW);
        }
    }
}