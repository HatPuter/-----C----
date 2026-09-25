#ifndef PRODUCER_SHOWCASE_H
#define PRODUCER_SHOWCASE_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class ProducerShowcase : public Node2D {
    GDCLASS(ProducerShowcase, Node2D);

public:
    void scene_finished();

protected:
    static void _bind_methods();

public:
    ProducerShowcase();
    ~ProducerShowcase();

    void _ready() override;
    void _process(double delta) override;
};

#endif // PRODUCER_SHOWCASE_H
