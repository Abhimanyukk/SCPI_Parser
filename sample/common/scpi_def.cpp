#include "scpi_def.hpp"

static scpi::result_t cbFunction(std::shared_ptr<scpi::Parser> parser)
{
    std::cout << "Command callback" << std::endl;
    return scpi::SCPI_RES_OK;
}

std::list<scpi::Commands> scpi_def::scpi_command_list{
    {"SCPI", &cbFunction},
    {"SCPI:SCPI", &cbFunction},
};
