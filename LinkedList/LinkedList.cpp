#include "LinkedListGodot/LinkedList.h"

LinkedList::LinkedList() {}

LinkedList::LinkedList(const LinkedList &linked_list)
: _linked_list(linked_list._linked_list) {}

Ref<LinkedListIterator> LinkedList::begin() const {
    Ref<LinkedListIterator> iterator;
    iterator.instantiate(_linked_list.begin());

    return iterator;
}

Ref<LinkedListIterator> LinkedList::end() const {
    Ref<LinkedListIterator> iterator;
    iterator.instantiate(_linked_list.end());

    return iterator;
}

Ref<LinkedListIterator> LinkedList::insert_value(const Variant &new_value) {
    Ref<LinkedListIterator> iterator;
    iterator.instantiate(_linked_list.insert(new_value));

    return iterator;
}

Ref<LinkedListIterator> LinkedList::insert_in_position(const size_t &pos, const Variant &new_value) {
    Ref<LinkedListIterator> iterator;
    iterator.instantiate(_linked_list.insert(pos, new_value));

    return iterator;
}

bool LinkedList::remove_value(const Variant &remove_value) {
    return _linked_list.remove(remove_value);
}

bool LinkedList::remove_in_position(const size_t &pos) {
    return _linked_list.remove(pos);
}

Ref<LinkedListIterator> LinkedList::get_pos(const size_t &pos) const {
    Ref<LinkedListIterator> iterator;
    iterator.instantiate(_linked_list.get(pos));

    return iterator;
}

Ref<LinkedListIterator> LinkedList::search(const Variant &value) const {
    Ref<LinkedListIterator> iterator;
    iterator.instantiate(_linked_list.search(value));

    return iterator;
}

size_t LinkedList::get_size() const {
    return _linked_list.get_size();
}

bool LinkedList::is_empty() const {
    return _linked_list.is_empty();
}

void LinkedList::_bind_methods() {
    ClassDB::bind_method(D_METHOD("begin"), static_cast<Ref<LinkedListIterator> (LinkedList::*)() const>(&LinkedList::begin));
    ClassDB::bind_method(D_METHOD("end"), static_cast<Ref<LinkedListIterator> (LinkedList::*)() const>(&LinkedList::end));

    ClassDB::bind_method(D_METHOD("insert_value", "new_value"), static_cast<Ref<LinkedListIterator> (LinkedList::*)(const Variant&)>(&LinkedList::insert_value));
    ClassDB::bind_method(D_METHOD("insert_in_position", "pos"), static_cast<Ref<LinkedListIterator> (LinkedList::*)(const size_t&, const Variant&)>(&LinkedList::insert_in_position));

    ClassDB::bind_method(D_METHOD("remove_value", "remove_value"), static_cast<bool (LinkedList::*)(const Variant&)>(&LinkedList::remove_value));
    ClassDB::bind_method(D_METHOD("remove_in_position", "pos"), static_cast<bool (LinkedList::*)(const size_t&)>(&LinkedList::remove_in_position));

    ClassDB::bind_method(D_METHOD("search", "value"), static_cast<Ref<LinkedListIterator> (LinkedList::*)(const Variant&) const>(&LinkedList::search));
    ClassDB::bind_method(D_METHOD("get_pos", "pos"), static_cast<Ref<LinkedListIterator> (LinkedList::*)(const size_t&) const>(&LinkedList::get_pos));

    ClassDB::bind_method(D_METHOD("get_size"), static_cast<size_t (LinkedList::*)() const>(&LinkedList::get_size));
    ClassDB::bind_method(D_METHOD("is_empty"), static_cast<bool (LinkedList::*)() const>(&LinkedList::is_empty));
}