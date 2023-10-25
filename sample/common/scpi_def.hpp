#pragma once

#include <scpi/scpi.hpp>

namespace scpi_def
{
    class ScpiDef : public scpi::ieee::IEEE
    {
    public:
        static std::vector<scpi::Commands> scpi_command_list;
        static scpi::result_t cbFunction(scpi::Parser *parser);
    };
}
