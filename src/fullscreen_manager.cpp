#include "../include/fullscreen_manager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/input_event.hpp>

using namespace godot;

FullscreenManager::FullscreenManager() {
}

FullscreenManager::~FullscreenManager() {
}

void FullscreenManager::_bind_methods() {
}

void FullscreenManager::_input(const Ref<InputEvent> &p_event) {
    // 创建监听对象
    Ref<InputEventKey> key_event = p_event;
    // 转换为键盘事件
    if (key_event.is_valid() && key_event->is_pressed() && !key_event->is_echo()) {
        // 是否按下F11键
        if (key_event->get_keycode() == KEY_F11) {
            DisplayServer* displayServer = DisplayServer::get_singleton();

            // 全屏
            if (displayServer->window_get_mode() == DisplayServer::WINDOW_MODE_EXCLUSIVE_FULLSCREEN) {
                displayServer->window_set_mode(DisplayServer::WINDOW_MODE_WINDOWED);
            }
            // 退出全屏
            else {
                displayServer->window_set_mode(DisplayServer::WINDOW_MODE_EXCLUSIVE_FULLSCREEN);
            }
        }
    }
}
