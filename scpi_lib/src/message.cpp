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
        std::cerr << "Exception: " << e.what() << std::endl;
        return false;
    }
}

void scpi::msg::Message::RemoveTerminations(std::string &message)
{
    message.erase(std::remove(message.begin(), message.end(), '\r'), message.end());
    message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
}

void scpi::msg::Message::Split(char delimiter)
{
    size_t start = 0, end = 0;

    while ((end = this->inputMsg.find(delimiter, start)) != std::string::npos)
    {
        this->inputMessageList.push_back(this->inputMsg.substr(start, end - start));
        start = end + 1;
    }

    this->inputMessageList.push_back(this->inputMsg.substr(start));
}

bool scpi::msg::Message::ProcessMessage()
{
    try
    {
        this->Split(';');

        int i = 0;
        for (std::string &message : this->inputMessageList)
        {
            this->RemoveLeadingSpace(message);
            this->RemoveTerminations(message);
            std::cout << "Message: " << message << std::endl;
        }

        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return false;
    }
}