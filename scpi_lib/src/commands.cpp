#include "scpi/commands.hpp"

bool Compare(char a, char b)
{
    return (std::tolower(a) == std::tolower(b));
}

bool scpi::Commands::HandleSpecialCharacters(char character, char command, int &cmdIndex, bool &optionalNode)
{
    bool result = true;

    switch (character)
    {
    case '*':
    case '?':
        if (!Compare(character, command))
        {
            return false;
        }
        cmdIndex += 1;
        break;

    case '#':
        if (std::isdigit(command))
        {
            cmdIndex += 1;
        }
        break;

    case ':':
        if (!optionalNode)
        {
            if (!Compare(character, command))
            {
                return false;
            }
            cmdIndex += 1;
        }
        else
        {
            if (Compare(character, command))
            {
                cmdIndex += 1;
            }
        }
        break;

    case '[':
        optionalNode = true;
        break;

    case ']':
        optionalNode = false;
        break;

    default:
        result = false;
        break;
    }

    return result;
}

#if 1
bool scpi::Commands::CheckSyntax(std::string cmd, std::function<result_t(std::shared_ptr<Parser>)> &cb)
{
    std::string commandSyntax = this->syntax;

    int cmdIndex = 0;
    bool firstLower = 0;
    bool firstLowerMatches = 0;
    bool optionalNode = false;
    bool nodeFirstCharMatches = false;

    for (const char character : commandSyntax)
    {
        if (std::isalpha(character))
        {
            if (std::isupper(character))
            {
                firstLowerMatches = false;
                firstLower = 0;
                if (!optionalNode)
                {
                    if (!Compare(character, cmd[cmdIndex]))
                    {
                        return false;
                    }
                    cmdIndex += 1;
                }
                else
                {
                    if (Compare(character, cmd[cmdIndex]))
                    {
                        nodeFirstCharMatches = true;
                        cmdIndex += 1;
                    }
                    else if (nodeFirstCharMatches)
                    {
                        return false;
                    }
                }
            }
            else if (!optionalNode)
            {
                if (!firstLower)
                {
                    firstLower = 1;

                    if (Compare(character, cmd[cmdIndex]))
                    {
                        cmdIndex += 1;
                        firstLowerMatches = 1;
                    }
                }
                else if (firstLowerMatches)
                {
                    if (!Compare(character, cmd[cmdIndex]))
                    {
                        return false;
                    }
                    cmdIndex += 1;
                }
            }
            else if (!firstLower)
            {
                firstLower = true;
                if (Compare(character, cmd[cmdIndex]))
                {
                    cmdIndex += 1;
                    firstLowerMatches = 1;
                }
                else if (firstLowerMatches)
                {
                    return false;
                }
            }
            else
            {
                if (firstLowerMatches)
                {
                    if (!Compare(character, cmd[cmdIndex]))
                    {
                        return false;
                    }
                    cmdIndex += 1;
                }
            }
        }
        else if (!this->HandleSpecialCharacters(character, cmd[cmdIndex], cmdIndex, optionalNode))
        {
            return false;
        }
    }

    std::cout << "Return true\n";

    return true;
}

#endif
