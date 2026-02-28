#include "headers/components.h"
#include "headers/controllers.h"

#include "oatpp/network/Server.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

void run() {

  AppComponent app_components;

  /* Create Router for HTTP requests routing */
  OATPP_COMPONENT(
    std::shared_ptr<oatpp::web::server::HttpRouter>, 
    router
  );

  auto ApiController = std::make_shared<Controller>();
  router->addController(ApiController);

  /* Create HTTP connection handler with router */
  OATPP_COMPONENT(
    std::shared_ptr<oatpp::network::ConnectionHandler>, 
    connectionHandler
  );

  /* Create TCP connection provider */
  OATPP_COMPONENT(
    std::shared_ptr<oatpp::network::ServerConnectionProvider>,
    connectionProvider
  );

  /* Create server which takes provided TCP connections 
  and passes them to HTTP connection handler */
  oatpp::network::Server server(
    connectionProvider, connectionHandler
  );

  /* Priny info about server port */
  OATPP_LOGI(
    "API", "Server running on port %s", 
    connectionProvider->getProperty("port").getData()
  );

  /* Run server */
  server.run();
}

int main() {

  /* Init oatpp Environment */
  oatpp::base::Environment::init();

  /* Run App */
  run();

  /* Destroy oatpp Environment */
  oatpp::base::Environment::destroy();

  return 0;

}
