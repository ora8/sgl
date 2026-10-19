#pragma once

#include <vector>

#include "msg.h"

namespace sgl
{

class msg_queue {
public:
    void add_msg(msg message) {
        _messages.push_back(std::move(message));
    }

    void process_all() {
        for (auto& message : _messages) {
            std::visit(process_msg{}, message);
        }
        _messages.clear();
    }
private:
    std::vector<msg> _messages;
};

}