#ifndef STACK_GODOT_H
#define STACK_GODOT_H

#include <stack/stack.h>

#include "core/object/ref_counted.h"

class Stack : public RefCounted {
    GDCLASS(Stack, RefCounted);

    static void _bind_methods();

    ds::stack<Variant> _stack;

public:
    Stack();

    void push(const Variant &new_value);
    void pop();

    Variant top() const;

    size_t get_size() const;

    bool is_empty() const;
};

#endif // STACK_GODOT_H