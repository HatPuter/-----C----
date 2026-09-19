#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class MainMenu : public Node2D {
    GDCLASS(MainMenu, Node2D);

public:
    void on_tween_finished();

protected:
    static void _bind_methods();

public:
    MainMenu();
    ~MainMenu();

    void _ready() override;
    void _process(double delta) override;
};

#endif // MAIN_MENU_H
