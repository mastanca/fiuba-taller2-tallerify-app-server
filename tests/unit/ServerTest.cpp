

#include "ServerTest.h"
#include "../../src/api/networking/Server.h"

void ServerTest::controllersRegistrationOnCreation() {
    Server server;

    ASSERT_GE(server.controllers.size(), 1);
}
