#include "scpi_def.hpp"

static void cbFunction(int *p)
{
    std::cout << "Command callback" << std::endl;
}

std::list<scpi::Commands> scpi_command_list{
    {"SCPI", &cbFunction},
    {"SCPI:SCPI", &cbFunction},
};
