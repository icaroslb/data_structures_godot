#include "StackGodot/Stack.h"

Stack::Stack()
: _stack() {}

void Stack::push(const Variant &new_value) {
    _stack.push(new_value);
}

void Stack::pop() {
    _stack.pop();
}

Variant Stack::top() const {
    return _stack.top();
}

size_t Stack::get_size() const {
    return _stack.get_size();
}

bool Stack::is_empty() const {
    return _stack.is_empty();
}


void Stack::_bind_methods() {
    ClassDB::bind_method(D_METHOD("push", "new_value"), static_cast<void (Stack::*)(const Variant&)>(&Stack::push));
    ClassDB::bind_method(D_METHOD("pop"), static_cast<void (Stack::*)()>(&Stack::pop));
    ClassDB::bind_method(D_METHOD("top"), static_cast<Variant (Stack::*)() const>(&Stack::top));

    ClassDB::bind_method(D_METHOD("get_size"), static_cast<size_t (Stack::*)() const>(&Stack::get_size));

    ClassDB::bind_method(D_METHOD("is_empty"), static_cast<bool (Stack::*)() const>(&Stack::is_empty));
}