#pragma once

#include <iostream>
#include <functional>
#include <memory>

namespace scpi
{
    class Parser;

    typedef enum
    {
        SCPI_RES_OK = 1,
        SCPI_RES_ERR = -1,
    } result_t;

    typedef enum
    {
        CTRL_SRQ = 1, /* service request */
        CTRL_GTL,     /* Go to local */
        CTRL_SDC,     /* Selected device clear */
        CTRL_PPC,     /* Parallel poll configure */
        CTRL_GET,     /* Group execute trigger */
        CTRL_TCT,     /* Take control */
        CTRL_LLO,     /* Device clear */
        CTRL_DCL,     /* Local lockout */
        CTRL_PPU,     /* Parallel poll unconfigure */
        CTRL_SPE,     /* Serial poll enable */
        CTRL_SPD,     /* Serial poll disable */
        CTRL_MLA,     /* My local address */
        CTRL_UNL,     /* Unlisten */
        CTRL_MTA,     /* My talk address */
        CTRL_UNT,     /* Untalk */
        CTRL_MSA      /* My secondary address */
    } ctrl_name_t;

    class Commands
    {
    private:
        std::string syntax;
        std::function<result_t(std::shared_ptr<Parser>)> callback;

    public:
        Commands(std::string cmds,
                 std::function<result_t(std::shared_ptr<Parser>)> cb) : syntax(cmds),
                                                                        callback(cb) {}
        bool CheckSyntax(std::string cmd, std::function<result_t(std::shared_ptr<Parser>)> &cb);
    };
}
