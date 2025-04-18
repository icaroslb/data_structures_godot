#ifndef SET_ITERATOR_GODOT_H
#define SET_ITERATOR_GODOT_H

#include <rb_tree/rb_tree.h>

#include "core/object/ref_counted.h"

class SetIterator : public RefCounted {
    GDCLASS(SetIterator, RefCounted);

    static void _bind_methods();

    ds::rb_tree<Variant>::Iterator _iterator;

public:
    SetIterator();
    SetIterator(const ds::rb_tree<Variant>::Iterator& iterator);
    SetIterator(const SetIterator& iterator);

    bool is_nil();
    Ref<SetIterator> next();
    Ref<SetIterator> prev();
    Variant get_value();

    Ref<SetIterator> operator++();
    Ref<SetIterator> operator--();
    Ref<SetIterator> operator++(int);
    Ref<SetIterator> operator--(int);

    const Variant& operator*();
    const Variant* operator->();

    bool operator==(const SetIterator& iterator);
    bool operator!=(const SetIterator& iterator);
};

#endif // SET_ITERATOR_H