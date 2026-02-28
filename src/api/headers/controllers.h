#ifndef HELLO_H
#define HELLO_H

#include "dtos.h"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/data/mapping/type/Object.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

// Controller class for creating and implementing API endpoints
class Controller : public oatpp::web::server::api::ApiController {
public:
    Controller(
        OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    )
        : oatpp::web::server::api::ApiController(objectMapper)
    {}
    
    ENDPOINT("GET", "/hello", hello) {
        auto dto = MessageDTO::createShared();
        dto->statusCode = 200;
        dto->message = "Good Meowrningggg!!";
        return createDtoResponse(Status::CODE_200, dto);
    }

    ENDPOINT("GET", "/test/{number}", getNumber, PATH(Int32, number))
    {
        OATPP_LOGD("Test", "number=%d", *number);
        return createResponse(Status::CODE_200, "Yay!!!");
    }

    // Add other endpoints here

};

#include OATPP_CODEGEN_END(ApiController)

#endif