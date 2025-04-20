#include "LinkedListGodot/LinkedListrIterator.h"

LinkedListrIterator::LinkedListrIterator() {}

LinkedListrIterator::LinkedListrIterator(const LinkedListrIterator& iterator)
: _iterator(iterator._iterator) {}

LinkedListrIterator::LinkedListrIterator(const ds::linked_list<Variant>::rIterator& iterator)
: _iterator(iterator) {}

Ref<LinkedListrIterator> LinkedListrIterator::next() {
    ++_iterator;
    return Ref<LinkedListrIterator>(this);
}

Ref<LinkedListrIterator> LinkedListrIterator::prev() {
    --_iterator;
    return Ref<LinkedListrIterator>(this);
}

Ref<LinkedListrIterator> LinkedListrIterator::operator++() {
    ++_iterator;
    return Ref<LinkedListrIterator>(this);
}

Ref<LinkedListrIterator> LinkedListrIterator::operator--() {
    --_iterator;
    return Ref<LinkedListrIterator>(this);
}

Ref<LinkedListrIterator> LinkedListrIterator::operator++(int) {
    Ref<LinkedListrIterator> old_iterator;
    old_iterator.instantiate(*this);
    ++_iterator;
    return old_iterator;
}

Ref<LinkedListrIterator> LinkedListrIterator::operator--(int) {
    Ref<LinkedListrIterator> old_iterator;
    old_iterator.instantiate(*this);
    --_iterator;
    return old_iterator;
}

bool LinkedListrIterator::is_null() {
    return _iterator.is_null();
}

Variant LinkedListrIterator::get_value() {
    return *_iterator;
}

Variant& LinkedListrIterator::operator*() {
    return *_iterator;
}

Variant* LinkedListrIterator::operator&() {
    return &_iterator;
}

void LinkedListrIterator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("is_null"), static_cast<bool (LinkedListrIterator::*)()>(&LinkedListrIterator::is_null));
    ClassDB::bind_method(D_METHOD("next"), static_cast<Ref<LinkedListrIterator> (LinkedListrIterator::*)()>(&LinkedListrIterator::next));
    ClassDB::bind_method(D_METHOD("prev"), static_cast<Ref<LinkedListrIterator> (LinkedListrIterator::*)()>(&LinkedListrIterator::prev));
    ClassDB::bind_method(D_METHOD("get_value"), static_cast<Variant (LinkedListrIterator::*)()>(&LinkedListrIterator::get_value));
}