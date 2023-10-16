#include <iostream>
#include <list>
#include <string>

#include <scpi/scpi.hpp>
#include "scpi_def.hpp"

scpi::Interface interface(

    /** SCPI Error Function **/
    [](std::shared_ptr<scpi::Parser> parser, int16_t error) -> int
    {
        std::cout << "SCPI Error Function" << std::endl;
        return 1;
    },

    /** SCPI Control Function **/
    [](std::shared_ptr<scpi::Parser> parser, scpi::ctrl_name_t ctrl_name, uint16_t stb) -> scpi::result_t
    {
        std::cout << "SCPI Control Function" << std::endl;
        return scpi::SCPI_RES_OK;
    });

int main()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "|            SCPI CLI TEST             |" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    scpi::Parser parser(
        scpi_def::scpi_command_list,
        interface,
        scpi::unit::unit_def,
        "MANUFACTURER",
        "MODEL",
        "SERIAL NUMBER",
        "VERSION");

    // parser.Input("*idn?");
    if (parser.Input("syst:pressure?") &&
        parser.Input("syst:pres?") &&
        !parser.Input("syste:pres?") &&
        !parser.Input("syst:press?"))
    {
        std::cout << "TEST ERR\n";
        return -1;
    }
    std::cout << "TEST OK\n";

    return 0;
}
