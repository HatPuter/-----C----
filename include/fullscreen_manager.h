#ifndef FULLSCREEN_MANAGER_H
#define FULLSCREEN_MANAGER_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>

using namespace godot;

class FullscreenManager : public Node {
    GDCLASS(FullscreenManager, Node);

protected:
    static void _bind_methods();

public:
    FullscreenManager();
    ~FullscreenManager();

    void _input(const Ref<InputEvent> &p_event) override;
};

#endif
