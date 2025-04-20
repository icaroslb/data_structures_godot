#ifndef SET_RITERATOR_GODOT_H
#define SET_RITERATOR_GODOT_H

#include <rb_tree/rb_tree.h>

#include "core/object/ref_counted.h"

class SetrIterator : public RefCounted {
    GDCLASS(SetrIterator, RefCounted);

    static void _bind_methods();

    ds::rb_tree<Variant>::rIterator _iterator;

public:
    SetrIterator();
    SetrIterator(const ds::rb_tree<Variant>::rIterator& iterator);
    SetrIterator(const SetrIterator& iterator);

    bool is_nil();
    Ref<SetrIterator> next();
    Ref<SetrIterator> prev();
    Variant get_value();

    Ref<SetrIterator> operator++();
    Ref<SetrIterator> operator--();
    Ref<SetrIterator> operator++(int);
    Ref<SetrIterator> operator--(int);

    const Variant& operator*();
    const Variant* operator->();

    bool operator==(const SetrIterator& iterator);
    bool operator!=(const SetrIterator& iterator);
};

#endif // SET_RITERATOR_H