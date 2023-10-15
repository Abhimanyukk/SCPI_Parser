#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <list>
#include "commands.hpp"

namespace scpi
{
    class Parser
    {
    private:
        std::list<Commands> commands;

    public:
        Parser(std::list<Commands> cmds);
        ~Parser();
    };
}

#endif /** PARSER_HPP **/
