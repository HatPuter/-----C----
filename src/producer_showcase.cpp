#include "../include/producer_showcase.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/property_tweener.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

using namespace godot;

ProducerShowcase::ProducerShowcase() {
}

ProducerShowcase::~ProducerShowcase() {
}

void ProducerShowcase::_bind_methods() {
}

void ProducerShowcase::_ready() {
    // 获取节点
    Label* content = Object::cast_to<Label>(get_node_or_null("Content"));

    // 设置颜色透明度
    Color colorTransparency = content->get_modulate();
    colorTransparency.a = 0.0;
    content->set_modulate(colorTransparency);
    
    // 初始化动画
    Ref<Tween> tween = create_tween();

    // 渐显
    tween->tween_property(content, "modulate:a", 1.0, 0.6);
    // 等待
    tween->tween_property(content, "modulate:a", 1.0, 1.6);
    // 渐隐
    tween->tween_property(content, "modulate:a", 0.0, 0.6);
    // 等待
    tween->tween_property(content, "modulate:a", 0.0, 1.6);

    // 切换场景
    get_tree()->change_scene_to_file("res://scenes/main_menu.tscn");
}

void ProducerShowcase::_process(double delta) {
}
