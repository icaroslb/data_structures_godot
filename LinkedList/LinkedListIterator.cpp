#include "LinkedListGodot/LinkedListIterator.h"

LinkedListIterator::LinkedListIterator() {}

LinkedListIterator::LinkedListIterator(const LinkedListIterator& iterator)
: _iterator(iterator._iterator) {}

LinkedListIterator::LinkedListIterator(const ds::linked_list<Variant>::Iterator& iterator)
: _iterator(iterator) {}

Ref<LinkedListIterator> LinkedListIterator::next() {
    ++_iterator;
    return Ref<LinkedListIterator>(this);
}

Ref<LinkedListIterator> LinkedListIterator::prev() {
    --_iterator;
    return Ref<LinkedListIterator>(this);
}

Ref<LinkedListIterator> LinkedListIterator::operator++() {
    ++_iterator;
    return Ref<LinkedListIterator>(this);
}

Ref<LinkedListIterator> LinkedListIterator::operator--() {
    --_iterator;
    return Ref<LinkedListIterator>(this);
}

Ref<LinkedListIterator> LinkedListIterator::operator++(int) {
    Ref<LinkedListIterator> old_iterator;
    old_iterator.instantiate(*this);
    ++_iterator;
    return old_iterator;
}

Ref<LinkedListIterator> LinkedListIterator::operator--(int) {
    Ref<LinkedListIterator> old_iterator;
    old_iterator.instantiate(*this);
    --_iterator;
    return old_iterator;
}

bool LinkedListIterator::is_null() {
    return _iterator.is_null();
}

Variant LinkedListIterator::get_value() {
    return *_iterator;
}

Variant& LinkedListIterator::operator*() {
    return *_iterator;
}

Variant* LinkedListIterator::operator&() {
    return &_iterator;
}

void LinkedListIterator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("is_null"), static_cast<bool (LinkedListIterator::*)()>(&LinkedListIterator::is_null));
    ClassDB::bind_method(D_METHOD("next"), static_cast<Ref<LinkedListIterator> (LinkedListIterator::*)()>(&LinkedListIterator::next));
    ClassDB::bind_method(D_METHOD("prev"), static_cast<Ref<LinkedListIterator> (LinkedListIterator::*)()>(&LinkedListIterator::prev));
    ClassDB::bind_method(D_METHOD("get_value"), static_cast<Variant (LinkedListIterator::*)()>(&LinkedListIterator::get_value));
}