#include "../include/producer_showcase.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/label.hpp>

using namespace godot;

ProducerShowcase::ProducerShowcase() {
}

ProducerShowcase::~ProducerShowcase() {
}

void ProducerShowcase::_bind_methods() {
}

void ProducerShowcase::_ready() {
    // 获取子节点 Label
    Label* label = get_node<Label>("Label");
    
    // 修改文字
    label->set_text("Hello, 福瑞！");
    
    // 修改位置
    label->set_position(Vector2(100, 200));

    // 修改颜色
    label->add_theme_color_override("font_color", Color(1, 0, 0));  // 红色
}

void ProducerShowcase::_process(double delta) {
    Label* label = get_node<Label>("Label");
    
    // 每帧旋转
    label->set_rotation(label->get_rotation() + delta);
    
    // 每帧移动
    Vector2 pos = label->get_position();
    pos.x += 50 * delta;
    label->set_position(pos);
}
