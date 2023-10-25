#pragma once
#include "scpi.hpp"

namespace scpi
{
    namespace ieee
    {
        class IEEE
        {
        protected:
            result_t CoreIdnQ(Parser *parser);
        };
    }
}