#ifndef POSTGRESQL_H
#define POSTGRESQL_H

#include "oatpp/orm/DbClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class PostgresClient : public oatpp::orm::DbClient
{
public:
    PostgresClient(const std::shared_ptr<oatpp::orm::Executor>& executor)
        : oatpp::orm::DbClient(executor)
    {}

    QUERY(
        getUserByEmail,
        "SLELECT * FROM users WHERE email:=email;",
        PARAM(oatpp::String, email)
    )

    // define queries here

};

#include OATPP_CODEGEN_END(DbClient)

#endif