#include <SPI.h>
//#include <nRF24L01p.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001"; //any 5-letter string (match with receiver)

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); //power amplifier level (MIN is lowest, for short distance)
  radio.stopListening(); //transmitter
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
