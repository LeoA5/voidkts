#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/core/macro/component.hpp"

#include "oatpp-postgresql/orm.hpp"

class AppComponent {
public:
    // Connection Provider component listens on the port
    OATPP_CREATE_COMPONENT(
        std::shared_ptr<oatpp::network::ServerConnectionProvider>, 
        serverConnectionProvider
    )([] {
        // Listen on LAN on port 9000
        return oatpp::network::tcp::server::
        ConnectionProvider::createShared(
            {"0.0.0.0", 9000, oatpp::network::Address::IP_4}
        );
    }());

    // HTTP Router component routs HTTP requests
    OATPP_CREATE_COMPONENT(
        std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter
    )([] {
        return oatpp::web::server::HttpRouter::createShared();
    }());

    OATPP_CREATE_COMPONENT(
        std::shared_ptr<oatpp::network::ConnectionHandler>,
        serverConnectionHandler
    )([] {
        // Get router component
        OATPP_COMPONENT(
            std::shared_ptr<oatpp::web::server::HttpRouter>, 
            router
        );
        return oatpp::web::server::
        HttpConnectionHandler::createShared(router);
    }());

    OATPP_CREATE_COMPONENT(
        std::shared_ptr<oatpp::data::mapping::ObjectMapper>, 
        apiObjectMapper
    )([] {
        return oatpp::parser::json::mapping::
        ObjectMapper::createShared();
    }());

    /*
    OATPP_CREATE_COMPONENT(
        std::shared_ptr<PostgresClient>, postgresClient
    )([] {

            auto connectionProvider = std::make_shared<oatpp::postgresql::
            ConnectionProvider>(
                "postgresql://host:pw@host.docker.internal:5432/postgres"
            );

            auto connectionPool = oatpp::postgresql::
            ConnectionPool::createShareD(
                connectionProvider,
                10, // Max connections
                std::chrono::seconds(5) // Connection TTL
            )

            auto executor = std::make_shared<oatpp::postgresql::Executor>(
                connectionPool
            );

            return std::make_shared<postgresClient>(executor);

        }());
    */

};

#endif