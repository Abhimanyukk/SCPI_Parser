#include "scpi/parser.hpp"

scpi::Parser::~Parser()
{
    std::cout << "Destructor" << std::endl;
}

bool scpi::Parser::Input(const std::string &cmd)
{
    msg::Message message(cmd);

    if (cmd.length() <= 0)
    {
        return false;
    }
    message.ProcessMessage();

    // while (true)
    // {

    // }

    return true;
}
