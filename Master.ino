#include <SPI.h>
#include <Ethernet_v2.h>
#include <RestServer.h>

#include "Configuracoes.h"
#include "Pinos.h"

// Reqesuts

void postLedStatusVerde(char * params = "")
{

	LOG_PRINTLN("POST: Setar ou Resetar LED Verde");

	if (strncmp(params, "active=0", 8) == 0)
	{

		statusLedSystemVerde = 0;

		digitalWrite(ledSystemVerde, LOW);

		LOG_PRINTLN("Led Verde: OFF");

	}
	else if (strncmp(params, "active=1", 8) == 0)
	{

		statusLedSystemVerde = 1;

		digitalWrite(ledSystemVerde, HIGH);

		LOG_PRINTLN("Led Verde: ON");
	}

	rest.addData("active", statusLedSystemVerde);
}

void getLedStatusVerde(char * params = "") {

	LOG_PRINTLN("GET: Verificar Estado do LED Verde");

	rest.addData("active", statusLedSystemVerde);
}

// Life Cycle

void setup()
{

	pinMode(ledSystemVerde, OUTPUT);

	LOG_BEGIN(115200);

	LOG_PRINTLN("Iniciando...");

	Ethernet.begin(mac, ip);

	server.begin();

	LOG_PRINT("IP do Servidor: ");
	LOG_PRINTLN(Ethernet.localIP());

	// Requests Sets

	rest.addRoute(POST, "/ledVerde", postLedStatusVerde);
	rest.addRoute(GET, "/ledVerde", getLedStatusVerde);
}

void loop()
{

	rest.run();
}