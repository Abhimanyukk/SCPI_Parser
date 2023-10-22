#include <iostream>
#include "scpi/message.hpp"

bool scpi::msg::Message::RemoveLeadingSpace(std::string &message)
{
    if (message.length() <= 0)
    {
        return false;
    }

    try
    {
        size_t noOfInitialSpace = message.find_first_not_of(" \t");
        if (noOfInitialSpace != std::string::npos)
        {
            message = message.substr(noOfInitialSpace);
        }
        else
        {
            message.clear();
        }

        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception [RemoveLeadingSpace]: " << e.what() << std::endl;
        return false;
    }
}

void scpi::msg::Message::RemoveTerminations(std::string &message)
{
    message.erase(std::remove(message.begin(), message.end(), '\r'), message.end());
    message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
}

std::vector<std::string> scpi::msg::Message::Split(std::string inputString, char delimiter)
{
    size_t start = 0, end = 0;
    std::vector<std::string> stringList;

    while ((end = inputString.find(delimiter, start)) != std::string::npos)
    {
        stringList.push_back(inputString.substr(start, end - start));
        start = end + 1;
    }

    stringList.push_back(inputString.substr(start));

    return stringList;
}

bool scpi::msg::Message::ProcessRawMessage(std::vector<Pattern> &patternList)
{
    try
    {
        this->rawMessageList = this->Split(this->inputMsg, ';');

        for (std::string &message : this->rawMessageList)
        {
            this->RemoveLeadingSpace(message);
            this->RemoveTerminations(message);
            patternList.push_back(Pattern(message));
            // Pattern singleMessage = Pattern(message);
            // this->FindCommandHeader()
        }

        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception [ProcessRawMessage]: " << e.what() << std::endl;
        return false;
    }
}

bool scpi::msg::Message::ProcessIndividualMessage(scpi::msg::Pattern individualMessage, std::vector<scpi::Commands> &commandList, scpi::Commands& commandFound)
{
    int i = 0;
    for (scpi::Commands command : commandList)
    {
        std::function<result_t(std::shared_ptr<Parser>)> cb;
        if (command.CheckSyntax(individualMessage.GetHeader(), cb))
        {
            commandFound = commandList[i];
            return true;
        }
        i++;
    }
    return false;
}

scpi::msg::Pattern::Pattern(std::string rawMessage)
{
    size_t spacePosition = rawMessage.find(' ');
    if (spacePosition != std::string::npos)
    {
        this->header = rawMessage.substr(0U, spacePosition);
        this->parameters = rawMessage.substr(spacePosition + 1);
    }
    else
    {
        this->header = rawMessage;
        this->parameters = "";
    }
    this->type = rawMessage.back() == '?' ? QUERY : COMMAND;

    std::cout << "Command header: " << this->header << std::endl;
    // std::cout << "Parameters: " << this->parameters << std::endl;
}

std::string scpi::msg::Pattern::GetHeader()
{
    return this->header;
}
