#ifndef LINKED_LIST_ITERATOR_GODOT_H
#define LINKED_LIST_ITERATOR_GODOT_H

#include <linked_list/linked_list.h>

#include "core/object/ref_counted.h"

class LinkedListIterator : public RefCounted {
    GDCLASS(LinkedListIterator, RefCounted);

    static void _bind_methods();

    ds::linked_list<Variant>::Iterator _iterator;

public:
    LinkedListIterator();
    LinkedListIterator(const LinkedListIterator& iterator);
    LinkedListIterator(const ds::linked_list<Variant>::Iterator& iterator);

    Ref<LinkedListIterator> next();
    Ref<LinkedListIterator> prev();
    bool is_null();

    Variant& operator*();
    Variant* operator&();

    Variant get_value();
};

#endif // LINKED_LIST_ITERATOR_GODOT_H