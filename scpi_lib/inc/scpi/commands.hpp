#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>
#include <functional>

namespace scpi
{
    class Commands
    {
    private:
        std::string command;
        std::function<void(int *)> callback;

    public:
        Commands(std::string cmds, std::function<void(int *)> cb);
    };
}

#endif /** COMMANDS_HPP **/
