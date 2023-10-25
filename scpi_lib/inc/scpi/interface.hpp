#pragma once

#include <iostream>
#include <functional>
#include <memory>

namespace scpi
{
    class Parser;

    class InterfaceEvents
    {
    protected:
        Parser &parser;

    public:
        InterfaceEvents(Parser &_parser) : parser(_parser) {}
        virtual void onError(Parser *_parser) {}
        virtual void onWrite(Parser *_parser) {}
    };
}