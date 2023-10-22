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

    std::vector<scpi::msg::Pattern> patternList;
    if (!message.ProcessRawMessage(patternList))
    {
        // Error Push
        return false;
    }

    for (scpi::msg::Pattern pattern : patternList)
    {
        Commands receivedCommand;

        if (message.ProcessIndividualMessage(pattern, this->commands, receivedCommand))
        {
            receivedCommand.CallFunction(nullptr);
        }
    }

    return true;
}
