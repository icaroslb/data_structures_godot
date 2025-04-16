#include "QueueGodot/Queue.h"

Queue::Queue()
: _queue() {}

void Queue::enqueue(const Variant &new_value) {
    _queue.enqueue(new_value);
}

void Queue::dequeue() {
    _queue.dequeue();
}

Variant Queue::head() const {
    return _queue.head();
}

Variant Queue::tail() const {
    return _queue.tail();
}

size_t Queue::get_size() const {
    return _queue.get_size();
}

bool Queue::is_empty() const {
    return _queue.is_empty();
}

void Queue::_bind_methods() {
    ClassDB::bind_method(D_METHOD("enqueue", "new_value"), static_cast<void (Queue::*)(const Variant&)>(&Queue::enqueue));
    ClassDB::bind_method(D_METHOD("dequeue"), static_cast<void (Queue::*)()>(&Queue::dequeue));
    ClassDB::bind_method(D_METHOD("head"), static_cast<Variant (Queue::*)() const>(&Queue::head));
    ClassDB::bind_method(D_METHOD("tail"), static_cast<Variant (Queue::*)() const>(&Queue::tail));

    ClassDB::bind_method(D_METHOD("get_size"), static_cast<size_t (Queue::*)() const>(&Queue::get_size));

    ClassDB::bind_method(D_METHOD("is_empty"), static_cast<bool (Queue::*)() const>(&Queue::is_empty));
}