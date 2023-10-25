#include "scpi_def.hpp"
#include "scpi/scpi.hpp"

scpi::result_t scpi_def::ScpiDef::cbFunction(scpi::Parser * parser)
{
    std::cout << "Command callback" << std::endl;
    return scpi::SCPI_RES_OK;
}

std::vector<scpi::Commands> scpi_def::ScpiDef::scpi_command_list{
    {"SYSTem#[:PRESsure]?", &cbFunction},
};
