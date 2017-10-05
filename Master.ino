#include <SPI.h>
#include <Ethernet_v2.h>
#include <RestServer.h>

#include "Configuracoes.h"
#include "Pinos.h"

// Light Requests

void postLight(char * params = "")
{

	LOG_PRINTLN("POST: Ligar ou Desligar a Luz.");

	if (strncmp(params, "active=0", 8) == 0)
		lightWith_0();

	else if (strncmp(params, "active=1", 8) == 0)
		lightWith_1();

	rest.addData("active", lightState);
}

void getLight(char * params = "")
{
	LOG_PRINTLN("GET: Verificar Estado da Luz.");

	rest.addData("active", lightState);
}

// Route Request

void postRouter(char * params = "")
{

	LOG_PRINTLN("POST: Ligar ou Desligar a Roteador.");

	if (strncmp(params, "active=0", 8) == 0)
		routerWith_0();

	else if (strncmp(params, "active=1", 8) == 0)
		routerWith_1();

	rest.addData("active", routerState);
}

void getRouter(char * params = "")
{
	LOG_PRINTLN("GET: Verificar Estado do Roteador.");

	rest.addData("active", routerState);
}

// Modem Request

void postModem(char * params = "")
{

	LOG_PRINTLN("POST: Ligar ou Desligar a Modem.");

	if (strncmp(params, "active=0", 8) == 0)
		modemWith_0();

	else if (strncmp(params, "active=1", 8) == 0)
		modemWith_1();

	rest.addData("active", modemState);
}

void getModem(char * params = "")
{
	LOG_PRINTLN("GET: Verificar Estado do Modem.");

	rest.addData("active", modemState);
}

// Life Cycle

void setup()
{
	LOG_BEGIN(115200);

	LOG_PRINTLN("Iniciando...");

	pinMode(lightPin, OUTPUT);
	pinMode(routerPin, OUTPUT);
	pinMode(modemPin, OUTPUT);

	Ethernet.begin(mac, ip);

	server.begin();

	LOG_PRINT("IP do Servidor: ");
	LOG_PRINTLN(Ethernet.localIP());

	LOG_PRINTLN("Cadastrando Requisições...");

	// Light Request
	rest.addRoute(POST, "/light", postLight);
	rest.addRoute(GET, "/light", getLight);

	// Route Request
	rest.addRoute(POST, "/router", postRouter);
	rest.addRoute(GET, "/router", getRouter);

	// Modem Request
	rest.addRoute(POST, "/modem", postModem);
	rest.addRoute(GET, "/modem", getModem);

	LOG_PRINTLN("Inicialização Completa.");
}

void loop()
{

	rest.run();
}

// Light

void lightWith_1() 
{
	lightState = 1;

	digitalWrite(lightPin, HIGH);

	LOG_PRINTLN("Luz: ON");
}

void lightWith_0() 
{
	lightState = 0;

	digitalWrite(lightPin, LOW);

	LOG_PRINTLN("Luz: OFF");
}

// Router

void routerWith_1() 
{
	routerState = 1;

	digitalWrite(routerPin, HIGH);

	LOG_PRINTLN("Roteador: ON");
}

void routerWith_0()
{
	routerState = 0;

	digitalWrite(routerPin, LOW);

	LOG_PRINTLN("Roteador: OFF");
}

// Modem

void modemWith_1()
{
	modemState = 1;

	digitalWrite(modemPin, HIGH);

	LOG_PRINTLN("Roteador: ON");
}

void modemWith_0()
{
	modemState = 0;

	digitalWrite(modemPin, LOW);

	LOG_PRINTLN("Roteador: OFF");
}