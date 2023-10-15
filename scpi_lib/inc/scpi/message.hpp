#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace scpi
{
    namespace msg
    {
        typedef enum
        {
            TERMINATION_SEMICOLON,
            TERMINATION_NL,
            TERMINATION_NONE,
        } termination_t;

        class Message
        {
        private:
            std::string inputMsg;
            termination_t msgTermination;
            std::vector<std::string> inputMessageList;

            bool RemoveLeadingSpace(std::string &message);
            void RemoveTerminations(std::string &message);
            void Split(char);

        public:
            Message(const std::string &msg) : inputMsg(msg) {}
            bool ProcessMessage();
        };
    }
}