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

    public:
        Parser(std::list<Commands> cmds,
               scpi::Interface _interface,
               std::list<unit::Units> _unit_def) : commands(cmds),
                                                   interface(_interface),
                                                   unit_def(_unit_def) {}
        ~Parser();
    };
}
