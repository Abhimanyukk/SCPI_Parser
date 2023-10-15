#pragma once

#include <scpi/scpi.hpp>

namespace scpi_def
{
    extern std::vector<scpi::Commands> scpi_command_list;

    class ScpiDef : public scpi::Parser
    {
    public:
        int SCPI_Error(int16_t error);
    };
}
