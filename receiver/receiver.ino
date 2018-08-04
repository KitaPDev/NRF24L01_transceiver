#include <SPI.h>
//#include <nRF24L01p.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001"; //any 5-letter string (match with transmitter)

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN); //power amplifier level (MIN is lowest, for short distance)
  radio.startListening(); //receiver
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
