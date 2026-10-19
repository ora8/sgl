#pragma once

#include <functional>
#include <print>
#include <variant>

namespace sgl
{
class create_msg {
public:
    create_msg()
    {
    }
    void process()
    {
        std::println("create_msg.process");
    }
};

class destroy_msg {
public:
    destroy_msg()
    {
    }
};

class show_msg {
public:
    show_msg()
    {
    }
};

// Visitor interface with operator()
class process_msg {
public:
    void operator()(create_msg& message) const
    {
        message.process();
    }
    void operator()(destroy_msg& message) const
    {
    }
    void operator()(show_msg& message) const
    {
    }
};

using msg = std::variant<create_msg, destroy_msg, show_msg>;

}