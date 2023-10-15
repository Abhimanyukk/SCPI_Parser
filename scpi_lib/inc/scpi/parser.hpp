#pragma once

#include <iostream>
#include <list>
#include "commands.hpp"
#include "interface.hpp"
#include "units.hpp"

namespace scpi
{
    class Parser
    {
    private:
        std::list<Commands> commands;
        Interface interface;
        std::list<unit::Units> unit_def;
        std::vector<std::string> idn_list;

    public:
        Parser(std::list<Commands> cmds,
               scpi::Interface _interface,
               std::list<unit::Units> _unit_def,
               std::string idn1,
               std::string idn2,
               std::string idn3,
               std::string idn4) : commands(cmds),
                                   interface(_interface),
                                   unit_def(_unit_def),
                                   idn_list({idn1, idn2, idn3, idn4}) {}

        bool Input(std::string cmd);

        ~Parser();
    };
}
