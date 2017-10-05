#ifndef PINOS
#define PINOS

#include <Arduino.h>

// Light
int lightPin = 13;
int lightState = 0;

// Router
int routerPin = 30;
int routerState = 1;

// Modem
int modemPin = 31;
int modemState = 1;

// Ethernet
byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x42, 0xCA };
IPAddress ip(192, 168, 0, 13);
byte gateway[] = { 192, 168, 0, 1 };
byte subnet[] = { 255, 255, 255, 0 };
EthernetServer server(80);

// REST Server
RestServer rest(server);

#endif // !PINOS
