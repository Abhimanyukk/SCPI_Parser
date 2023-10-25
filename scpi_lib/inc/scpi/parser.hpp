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
        std::vector<Commands> commands;
        // Interface interface;
        std::list<unit::Units> unit_def;
        std::vector<std::string> idn_list;
        InterfaceEvents *interfaceHandler;

    public:
        Parser(std::vector<Commands> _cmds,
               //    scpi::Interface _interface,
               std::list<unit::Units> _unit_def,
               const std::string &_idn1,
               const std::string &_idn2,
               const std::string &_idn3,
               const std::string &_idn4) : commands(_cmds),
                                           //   interface(_interface),
                                           unit_def(_unit_def),
                                           idn_list({_idn1, _idn2, _idn3, _idn4})
        {
        }

        bool Input(const std::string &cmd);
        void RegisterInterface(InterfaceEvents *handler);

        bool ErrorHandler()
        {
            interfaceHandler->onError(this);
            return true;
        }

        void PrintIdn(int k)
        {
            std::cout << idn_list[k] << std::endl;
        }

        ~Parser();
    };
}
