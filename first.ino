
/*
int redpin = 11;  // select the pin for the red LED
int bluepin = 10; // select the pin for the  blue LED
int greenpin = 9; // select the pin for the green LED

int val;

void setup()
{
    pinMode(redpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    pinMode(greenpin, OUTPUT);

    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    
    val = 0;
    analogWrite(9, 0);    // green
    analogWrite(10, 0);   // blue
    analogWrite(11, 0); // red

    digitalWrite(LED_BUILTIN, HIGH);  
    delay(1000); 
    digitalWrite(LED_BUILTIN, LOW);  

    for (val = 0; val < 255; val++)
    {
        analogWrite(redpin,255-val);
        analogWrite(bluepin, val);
        delay(10);
    } // red to blue

    digitalWrite(LED_BUILTIN, HIGH);  
    delay(1000); 
    digitalWrite(LED_BUILTIN, LOW); 

    for (val = 0; val < 255; val++)
    {
        analogWrite(greenpin,val);
        analogWrite(bluepin, 255-val);
        delay(10);
    } // blue to green

    digitalWrite(LED_BUILTIN, HIGH);  
    delay(1000); 
    digitalWrite(LED_BUILTIN, LOW); 

    for (val = 0; val < 255; val++)
    {
        analogWrite(redpin,val);
        analogWrite(greenpin, 255-val);
        delay(10);
    } // green to red


    //red led
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);  


    Serial.println(val, DEC);
}
*/