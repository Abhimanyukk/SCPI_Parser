#include "scpi/ieee.hpp"

scpi::result_t scpi::ieee::IEEE::CoreIdnQ(scpi::Parser *parser)
{
    std::cout << "IDN read\n";

    return SCPI_RES_OK;
}
