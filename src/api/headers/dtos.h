#ifndef DTOS_H
#define DTOS_H

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/data/mapping/type/Object.hpp"

// Begin DTO codegen
#include OATPP_CODEGEN_BEGIN(DTO)

/*
    Message DTO
*/
class MessageDTO : public oatpp::DTO {
    DTO_INIT(MessageDTO, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(String, message);
};

// Add more DTOs here

// End DTO codegen
#include OATPP_CODEGEN_END(DTO)

#endif