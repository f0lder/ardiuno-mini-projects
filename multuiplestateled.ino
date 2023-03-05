/*
#define RED_PIN 11
#define BLUE_PIN 10
#define GREEN_PIN 9
#define BUTTON_PIN 7
#define STATUS_LED_PIN 8

byte lastButtonState = LOW;
int currentstate = 1;
void setup()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT);
    pinMode(STATUS_LED_PIN, OUTPUT);

    Serial.begin(9600);

    setColor(255, 0, 0);
}

void loop()
{

    // Serial.println(digitalRead(BUTTON_PIN), BIN);

    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) // press the button
    {
        lastButtonState = buttonState; // the state is in pressed state
        if (buttonState == LOW)        // button is released
        {
            nextState(currentstate);
        }
    }
    // delay(1000);
    // Serial.println(currentstate,DEC);
}

void setColor(int r, int b, int g)
{
    digitalWrite(RED_PIN, r);
    digitalWrite(BLUE_PIN, b);
    digitalWrite(GREEN_PIN, g);
}

void nextState(int &s)
{
    // 1 = red 2 = blue 3 = green
    setColor(255 * (s == 1), 255 * (s == 2), 255 * (s == 3));
    if (s == 3)
    {
        s = 1;
    }
    else
    {
        s++;
    }
}

*/