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
    void process()
    {
        std::println("destroy_msg.process");
    }
};

class show_msg {
public:
    show_msg()
    {
    }
    void process()
    {
        std::println("show_msg.process");
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
        message.process();
    }
    void operator()(show_msg& message) const
    {
        message.process();
    }
};

using msg = std::variant<create_msg, destroy_msg, show_msg>;

}