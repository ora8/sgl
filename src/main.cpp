#include "msg.h"
#include "msg_queue.h"

int main() {
    sgl::msg_queue queue;

    // Nachrichten zur Queue hinzufügen
    queue.add_msg(sgl::create_msg{});
    queue.add_msg(sgl::show_msg{});
    queue.add_msg(sgl::destroy_msg{});

    queue.process_all();

    return 0;
}
