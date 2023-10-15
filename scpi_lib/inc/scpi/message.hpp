#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "commands.hpp"

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

        typedef enum
        {
            COMMAND,
            QUERY
        } type_t;

        class Pattern
        {
        private:
            std::string header;
            type_t type;
            std::string parameters;

        public:
            Pattern(std::string message);
            std::string GetHeader();
        };

        class Message
        {
        private:
            std::string inputMsg;
            termination_t msgTermination;
            std::vector<std::string> rawMessageList;
            // std::vector<Pattern> patternList;

            bool RemoveLeadingSpace(std::string &message);
            void RemoveTerminations(std::string &message);
            std::vector<std::string> Split(std::string inputString, char delimeter);

        public:
            Message(const std::string &msg) : inputMsg(msg) {}
            bool ProcessRawMessage(std::vector<Pattern> &patternList);
            bool ProcessIndividualMessage(scpi::msg::Pattern individualMessage, const std::vector<scpi::Commands> &commandList);
        };
    }
}