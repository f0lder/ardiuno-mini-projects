/*
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5
#define RELAY_PIN A5 // the Arduino pin connects to relay

#define RED_PIN 2
#define GREEN_PIN 3
#define BLUE_PIN 4

#define BUZZER 9
MFRC522 rfid(SS_PIN, RST_PIN);

byte keyTagUID[4] = {0x8C, 0x5E, 0xC8, 0x38};

void setup()
{

  Serial.begin(9600);
  SPI.begin();     // init SPI bus
  rfid.PCD_Init(); // init MFRC522
  Serial.println(rfid.PCD_PerformSelfTest() ? "OK" : "ERR");
  rfid.PCD_Init(); // init MFRC522

  bool hasFailed;

  while (!rfid.PCD_PerformSelfTest())
  {
    hasFailed = true;
    Serial.println("FAil");
    delay(100);
  }
  if (hasFailed)
  {
    rfid.PCD_Init();
  }

  pinMode(RELAY_PIN, OUTPUT);    // initialize pin as an output.
  digitalWrite(RELAY_PIN, HIGH); // lock the door
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);

  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop()
{

  // Serial.println(rfid.PCD_GetAntennaGain(),DEC);
  // delay(1000);
  if (rfid.PICC_IsNewCardPresent())
  { // new tag is available
    if (rfid.PICC_ReadCardSerial())
    { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

      if (rfid.uid.uidByte[0] == keyTagUID[0] &&
          rfid.uid.uidByte[1] == keyTagUID[1] &&
          rfid.uid.uidByte[2] == keyTagUID[2] &&
          rfid.uid.uidByte[3] == keyTagUID[3])
      {
        Serial.println("Access is granted");
        // digitalWrite(RELAY_PIN, LOW);  // unlock the door for 2 seconds
        // delay(2000);
        // digitalWrite(RELAY_PIN, HIGH); // lock the door


        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 0);
        tone(BUZZER,30);
        delay(300);
        noTone(BUZZER);
        delay(100);
        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 255);
        analogWrite(BLUE_PIN, 0);
        tone(BUZZER,800);
        delay(1000);
        noTone(BUZZER);

        analogWrite(RED_PIN, 255);
        analogWrite(GREEN_PIN, 255);
        analogWrite(BLUE_PIN, 255);
      }
      else
      {
        Serial.print("Access denied for user with UID:");
        for (int i = 0; i < rfid.uid.size; i++)
        {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();

        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 0);
        tone(BUZZER,30);
        delay(300);
        noTone(BUZZER);
        delay(100);
        analogWrite(RED_PIN, 255);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 0);
        tone(BUZZER,200);
        delay(1000);
        noTone(BUZZER);

        analogWrite(RED_PIN, 255);
        analogWrite(GREEN_PIN, 255);
        analogWrite(BLUE_PIN, 255);
      }

      rfid.PICC_HaltA();      // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
*/