#ifndef LINKED_LIST_RITERATOR_GODOT_H
#define LINKED_LIST_RITERATOR_GODOT_H

#include <linked_list/linked_list.h>

#include "core/object/ref_counted.h"

class LinkedListrIterator : public RefCounted {
    GDCLASS(LinkedListrIterator, RefCounted);

    static void _bind_methods();

    ds::linked_list<Variant>::rIterator _iterator;

public:
    LinkedListrIterator();
    LinkedListrIterator(const LinkedListrIterator& iterator);
    LinkedListrIterator(const ds::linked_list<Variant>::rIterator& iterator);

    Ref<LinkedListrIterator> next();
    Ref<LinkedListrIterator> prev();

    Ref<LinkedListrIterator> operator++();
    Ref<LinkedListrIterator> operator--();

    Ref<LinkedListrIterator> operator++(int);
    Ref<LinkedListrIterator> operator--(int);

    bool is_null();

    Variant& operator*();
    Variant* operator&();

    Variant get_value();
};

#endif // LINKED_LIST_ITERATOR_GODOT_H