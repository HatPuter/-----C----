#include "../include/producer_showcase.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/tween.hpp>
#include <godot_cpp/classes/property_tweener.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/interval_tweener.hpp>

using namespace godot;

ProducerShowcase::ProducerShowcase() {
}

ProducerShowcase::~ProducerShowcase() {
}

void ProducerShowcase::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_tween_finished"), &ProducerShowcase::on_tween_finished);
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
    tween->tween_property(content, "modulate:a", 1.0, 0.4);
    // 等待
    tween->tween_interval(1.6);
    // 渐隐
    tween->tween_property(content, "modulate:a", 0.0, 0.4);
    // 等待
    tween->tween_interval(1.6);

    // 切换场景
    tween->connect("finished", Callable(this, StringName("on_tween_finished")));
}

void ProducerShowcase::_process(double delta) {
}

void ProducerShowcase::on_tween_finished() {
    get_tree()->change_scene_to_file("res://scenes/main_menu.tscn");
}
