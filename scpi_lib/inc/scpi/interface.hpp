#pragma once

#include <iostream>
#include <functional>
#include <memory>

namespace scpi
{
    class Parser;

    class Interface
    {
    private:
        std::function<int(std::shared_ptr<Parser>, int16_t error)>
            error_callback;
        std::function<result_t(std::shared_ptr<Parser>,
                               scpi::ctrl_name_t, uint16_t)>
            control_callback;

    public:
        Interface(
            std::function<int(std::shared_ptr<Parser>, int16_t error)>
                err_cb,
            std::function<result_t(std::shared_ptr<Parser>,
                                   scpi::ctrl_name_t, uint16_t)>
                ctrl_cb) : error_callback(err_cb),
                           control_callback(ctrl_cb) {}
    };
}