#ifndef  CONFIGURACOES
#define CONFIGURACOES

#include <Arduino.h>

#define DEBUG 1

#if DEBUG
#define LOG_BEGIN(x) Serial.begin(x)
#define LOG_PRINT(...) Serial.print(__VA_ARGS__)
#define LOG_PRINTLN(...) Serial.println(__VA_ARGS__)
#else
#define LOG_BEGIN(x)
#define LOG_PRINT(...)
#define LOG_PRINTLN(...)
#endif // ! DEBUG

#endif // ! CONFIGURACOES