#include "../include/main_menu.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/property_tweener.hpp>
#include <godot_cpp/classes/label.hpp>

using namespace godot;

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
}

void MainMenu::_bind_methods() {
    //ClassDB::bind_method(D_METHOD("on_tween_finished"), &MainMenu::on_tween_finished);
}

void MainMenu::_ready() {
    // 获取节点
    Label *title = Object::cast_to<Label>(get_node_or_null("Title"));
    Label *startGame = Object::cast_to<Label>(get_node_or_null("StartGame"));
    Label *continueGame = Object::cast_to<Label>(get_node_or_null("ContinueGame"));
    Label *setting = Object::cast_to<Label>(get_node_or_null("Setting"));
    Label *exit = Object::cast_to<Label>(get_node_or_null("Exit"));

    // 设置颜色透明度
    Color colorTransparency = title->get_modulate();
    colorTransparency.a = 0.0;
    title->set_modulate(colorTransparency);
    startGame->set_modulate(colorTransparency);
    continueGame->set_modulate(colorTransparency);
    setting->set_modulate(colorTransparency);
    exit->set_modulate(colorTransparency);

    // 初始化动画
    Ref<Tween> tween = create_tween();

    // 渐显
    tween->tween_property(title, "modulate:a", 1.0, 0.4);

    tween->tween_property(startGame, "modulate:a", 1.0, 0.25);
    tween->tween_property(continueGame, "modulate:a", 1.0, 0.2);
    tween->tween_property(setting, "modulate:a", 1.0, 0.15);
    tween->tween_property(exit, "modulate:a", 1.0, 0.1);
}

void MainMenu::_process(double delta) {
}

void MainMenu::on_tween_finished() {
}
