#include "scpi/units.hpp"

std::list<scpi::unit::Units> scpi::unit::unit_def{
    {/* name */ "UA", /* unit */ scpi::unit::SCPI_UNIT_AMPER, /* multiple */ 1e-6},
    {/* name */ "MA", /* unit */ scpi::unit::SCPI_UNIT_AMPER, /* multiple */ 1e-3},
    {/* name */ "A", /* unit */ scpi::unit::SCPI_UNIT_AMPER, /* multiple */ 1},
    {/* name */ "KA", /* unit */ scpi::unit::SCPI_UNIT_AMPER, /* multiple */ 1e3}};
