#ifndef QUEUE_GODOT_H
#define QUEUE_GODOT_H

#include <queue/queue.h>

#include "core/object/ref_counted.h"

class Queue : public RefCounted {
    GDCLASS(Queue, RefCounted);

    static void _bind_methods();

    ds::queue<Variant> _queue;

public:
    Queue();

    void enqueue(const Variant &new_value);
    void dequeue();

    Variant head() const;
    Variant tail() const;

    size_t get_size() const;

    bool is_empty() const;
};

#endif // QUEUE_GODOT_H