#ifndef LINKED_LIST_GODOT
#define LINKED_LIST_GODOT

#include "LinkedListIterator.h"

class LinkedList : public RefCounted {
    GDCLASS(LinkedList, RefCounted);

    static void _bind_methods();

    ds::linked_list<Variant> _linked_list;
public:
    LinkedList();
    LinkedList(const LinkedList& linked_list);

    Ref<LinkedListIterator> begin() const;
    Ref<LinkedListIterator> end() const;

    Ref<LinkedListIterator> insert_value(const Variant &new_value);
    Ref<LinkedListIterator> insert_in_position(const size_t &pos, const Variant &new_value);

    bool remove_value(const Variant &remove_value);
    bool remove_in_position(const size_t &pos);

    Ref<LinkedListIterator> get_pos(const size_t &pos) const;
    Ref<LinkedListIterator> search(const Variant &value) const;

    size_t get_size() const;
    bool is_empty() const;
};

#endif // LINKED_LIST_GODOT