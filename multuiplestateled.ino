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
    pinMode(STATUS_LED_PIN,OUTPUT);

    Serial.begin(9600);

    switchToNextColor(255,0,0);
}

void loop()
{

    // Serial.println(digitalRead(BUTTON_PIN), BIN);

    byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState)
    {
        lastButtonState = buttonState;
        if (buttonState == LOW)
        {
            switch (currentstate)
            {
            case 1:
            {
                // next state is blue
                switchToNextColor(0, 255, 0);
                digitalWrite(STATUS_LED_PIN,LOW);
                currentstate ++;
            }
            break;

            case 2:
            {
                // next state is green
                switchToNextColor(0, 0, 255);
                currentstate ++;
                 digitalWrite(STATUS_LED_PIN,HIGH);
            }

            break;

            case 3:
            {
                // next state is red
                switchToNextColor(255, 0, 0);
                currentstate = 1;
                digitalWrite(STATUS_LED_PIN,LOW);
            }
            default:
                break;
            }
        }
    }
    // delay(1000);
    Serial.println(currentstate,DEC);
}

void switchToNextColor(int r, int b, int g)
{
    digitalWrite(RED_PIN, r);
    digitalWrite(BLUE_PIN, b);
    digitalWrite(GREEN_PIN, g);
}