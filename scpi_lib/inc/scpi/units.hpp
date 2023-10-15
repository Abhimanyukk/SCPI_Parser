#pragma once

#include <iostream>
#include <list>

namespace scpi
{
    namespace unit
    {
        typedef enum
        {
            SCPI_UNIT_NONE,
            SCPI_UNIT_VOLT,
            SCPI_UNIT_AMPER,
            SCPI_UNIT_OHM,
        } unit_t;

        class Units
        {
        private:
            std::string name;
            unit_t unit;
            double multiple;

        public:
            Units(
                std::string _name,
                unit_t _unit,
                double _multiple) : name(_name),
                                    unit(_unit),
                                    multiple(_multiple) {}
        };

        extern std::list<Units> unit_def;
    }
}
