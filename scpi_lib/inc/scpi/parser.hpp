#pragma once

#include <iostream>
#include <list>
#include "commands.hpp"
#include "interface.hpp"
#include "units.hpp"
#include "message.hpp"

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
               const std::string &idn1,
               const std::string &idn2,
               const std::string &idn3,
               const std::string &idn4) : commands(cmds),
                                          interface(_interface),
                                          unit_def(_unit_def),
                                          idn_list({idn1, idn2, idn3, idn4})
        {
            std::cout << idn_list[2] << std::endl;
        }

        bool Input(const std::string &cmd);

        ~Parser();
    };
}
