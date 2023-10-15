#include "scpi/commands.hpp"

scpi::Commands::Commands(std::string cmds, std::function<void(int *)> cb)
{
    this->command = cmds;
    this->callback = cb;
}