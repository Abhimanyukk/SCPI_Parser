#include "scpi/commands.hpp"

bool Compare(char a, char b)
{
    return (std::tolower(a) == std::tolower(b));
}

// bool scpi::Commands::CheckSyntax(std::string cmd, std::function<result_t(std::shared_ptr<Parser>)> &cb)
// {
//     int cmdIndex = 0;
//     bool optionalNode = false;
//     bool nodeFirstCharacterMatches = false;
//     std::string commandSyntax = this->syntax;

//     for (char character : commandSyntax)
//     {
//         if (std::isalpha(character))
//         {
//             if (std::isupper(character))
//             {
//                 if (!optionalNode && !Compare(character, cmd[cmdIndex]))
//                 {
//                     return false;
//                 }
//                 cmdIndex += 1;
//             }
//             else
//             {
//                 if (!optionalNode && !nodeFirstCharacterMatches)
//                 {
//                     return false;
//                 }

//                 if (Compare(character, cmd[cmdIndex]))
//                 {
//                     cmdIndex += 1;
//                     nodeFirstCharacterMatches = true;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//         }
//         else
//         {
//             switch (character)
//             {
//             case '*':
//             case '?':
//                 if (!Compare(character, cmd[cmdIndex]))
//                 {
//                     return false;
//                 }
//                 cmdIndex += 1;
//                 break;

//             case '#':
//                 if (!std::isdigit(cmd[cmdIndex]))
//                 {
//                     return false;
//                 }
//                 cmdIndex += 1;
//                 break;

//             case ':':
//                 if (!optionalNode && !Compare(character, cmd[cmdIndex]))
//                 {
//                     return false;
//                 }
//                 cmdIndex += 1;
//                 break;

//             case '[':
//                 optionalNode = true;
//                 break;

//             case ']':
//                 optionalNode = false;
//                 break;

//             default:
//                 // Handle other characters if needed
//                 break;
//             }
//         }
//     }

//     return true;
// }

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
            std::cout << character << " is alpha\n";
            if (std::isupper(character))
            {
                firstLowerMatches = false;
                firstLower = 0;
                if (!optionalNode)
                {
                    if (!Compare(character, cmd[cmdIndex]))
                    {
                        std::cout << character << " is not equal to " << cmd[cmdIndex] << "\n";
                        std::cout << "Return due to 1" << std::endl;
                        return false;
                    }
                    std::cout << character << " is equal to " << cmd[cmdIndex] << "\n";
                    cmdIndex += 1;
                }
                else
                {
                    if (Compare(character, cmd[cmdIndex]))
                    {
                        nodeFirstCharMatches = true;
                        cmdIndex += 1;
                    }
                    else
                    {
                        if (nodeFirstCharMatches)
                        {
                            std::cout << "Return due to 2" << std::endl;
                            return false;
                        }
                    }
                }
            }
            else
            {
                if (!optionalNode)
                {
                    if (!firstLower)
                    {
                        firstLower = 1;
                        std::cout << character << " is lower\n";

                        if (Compare(character, cmd[cmdIndex]))
                        {
                            std::cout << character << " is equal to " << cmd[cmdIndex] << "\n";
                            cmdIndex += 1;
                            firstLowerMatches = 1;
                        }
                        std::cout << character << " is not equal to " << cmd[cmdIndex] << "\n";
                    }
                    else
                    {
                        if (firstLowerMatches)
                        {
                            if (!Compare(character, cmd[cmdIndex]))
                            {
                                std::cout << "Return due to 3" << std::endl;
                                return false;
                            }
                            cmdIndex += 1;
                        }
                    }
                }
                else
                {
                    if (!firstLower)
                    {
                        firstLower = true;
                        if (Compare(character, cmd[cmdIndex]))
                        {
                            cmdIndex += 1;
                            firstLowerMatches = 1;
                        }
                        else
                        {
                            if (firstLowerMatches)
                            {
                                std::cout << "Return due to 4" << std::endl;
                                return false;
                            }
                            // cmdIndex += 1;
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
            }
        }
        else
        {
            std::cout << character << " is not alpha\n";
            if (character == '*')
            {
                std::cout << character << " is '*'\n";
                if (!Compare(character, cmd[cmdIndex]))
                {
                    std::cout << character << " is not equal to " << cmd[cmdIndex] << "\n";
                    std::cout << "Return due to 5" << std::endl;
                    return false;
                }
                std::cout << character << " is equal to " << cmd[cmdIndex] << "\n";
                cmdIndex += 1;
            }
            else if (character == '#')
            {
                std::cout << character << " is '#'\n";
                if (std::isdigit(cmd[cmdIndex]))
                {
                    std::cout << cmd[cmdIndex] << " is digit\n";
                    cmdIndex += 1;
                }
            }
            else if (character == ':')
            {
                if (!optionalNode)
                {
                    std::cout << character << " is ':'\n";
                    if (!Compare(character, cmd[cmdIndex]))
                    {
                        std::cout << character << " is not equal to " << cmd[cmdIndex] << "\n";
                        std::cout << "Return due to 6" << std::endl;
                        return false;
                    }
                    std::cout << character << " is equal to " << cmd[cmdIndex] << "\n";
                    cmdIndex += 1;
                }
                else
                {
                    if (Compare(character, cmd[cmdIndex]))
                    {
                        cmdIndex += 1;
                    }
                }
            }
            else if (character == '?')
            {
                std::cout << character << " is '?'\n";
                if (!Compare(character, cmd[cmdIndex]))
                {
                    std::cout << character << " is not equal to " << cmd[cmdIndex] << "\n";
                    std::cout << "Return due to 7" << std::endl;
                    return false;
                }
                std::cout << character << " is equal to " << cmd[cmdIndex] << "\n";
                cmdIndex += 1;
            }

            else if (character == '[')
            {
                optionalNode = true;
            }
            else if (character == ']')
            {
                optionalNode = false;
            }
        }
    }

    std::cout << "Return true\n";

    return true;
}