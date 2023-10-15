#include "scpi/parser.hpp"

scpi::Parser::Parser(std::list<Commands> cmds)
{
    this->commands = cmds;
    std::cout << "Parser" << std::endl;
}

scpi::Parser::~Parser()
{
    std::cout << "Oyye" << std::endl;
}
