#include "Set/SetIterator.h"

SetIterator::SetIterator() : _iterator() {}

SetIterator::SetIterator(const ds::rb_tree<Variant>::Iterator& iterator) : _iterator(iterator) {}

SetIterator::SetIterator(const SetIterator& iterator) : _iterator(iterator._iterator) {}

bool SetIterator::is_nil() {
    return _iterator.is_nil();
}

Variant SetIterator::next() {
    return *(_iterator++);
}

SetIterator& SetIterator::operator++() {
    ++_iterator;
    return *this;
}

SetIterator& SetIterator::operator--() {
    ++_iterator;
    return *this;
}

SetIterator SetIterator::operator++(int) {
    SetIterator old_iterator = *this;
    _iterator++;
    return old_iterator;
}

SetIterator SetIterator::operator--(int) {
    SetIterator old_iterator = *this;
    _iterator--;
    return old_iterator;
}

const Variant& SetIterator::operator*() {
    return *_iterator;
}

const Variant* SetIterator::operator->() {
    return _iterator.operator->();
}

bool SetIterator::operator==(const SetIterator& iterator) {
    return _iterator == iterator._iterator;
}

bool SetIterator::operator!=(const SetIterator& iterator) {
    return _iterator != iterator._iterator;
}

void SetIterator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("is_nil"), static_cast<bool (SetIterator::*)()>(&SetIterator::is_nil));
    ClassDB::bind_method(D_METHOD("next"), static_cast<Variant (SetIterator::*)()>(&SetIterator::next));
}