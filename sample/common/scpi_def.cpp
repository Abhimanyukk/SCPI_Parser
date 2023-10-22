#include "scpi_def.hpp"

static scpi::result_t cbFunction(scpi::Parser * parser)
{
    std::cout << "Command callback" << std::endl;
    return scpi::SCPI_RES_OK;
}

std::vector<scpi::Commands> scpi_def::scpi_command_list{
    {"*IDN?", &cbFunction},
    {"SYSTem#[:PRESsure]?", &cbFunction},
};
