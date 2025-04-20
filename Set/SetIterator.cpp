#include "SetGodot/SetIterator.h"

SetIterator::SetIterator() : _iterator() {}

SetIterator::SetIterator(const ds::rb_tree<Variant>::Iterator& iterator) : _iterator(iterator) {}

SetIterator::SetIterator(const SetIterator& iterator) : _iterator(iterator._iterator) {}

bool SetIterator::is_nil() {
    return _iterator.is_nil();
}

Ref<SetIterator> SetIterator::next() {
    ++_iterator;
    return Ref<SetIterator>(this);
}


Ref<SetIterator> SetIterator::prev() {
    --_iterator;
    return Ref<SetIterator>(this);
}

Variant SetIterator::get_value() {
    return *_iterator;
}

Ref<SetIterator> SetIterator::operator++() {
    ++_iterator;

    return Ref<SetIterator>(this);
}

Ref<SetIterator> SetIterator::operator--() {
    --_iterator;
    
    return Ref<SetIterator>(this);
}

Ref<SetIterator> SetIterator::operator++(int) {
    Ref<SetIterator> old_iterator;
    old_iterator.instantiate(*this);

    _iterator++;

    return old_iterator;
}

Ref<SetIterator> SetIterator::operator--(int) {
    Ref<SetIterator> old_iterator;
    old_iterator.instantiate(*this);

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
    ClassDB::bind_method(D_METHOD("next"), static_cast<Ref<SetIterator> (SetIterator::*)()>(&SetIterator::next));
    ClassDB::bind_method(D_METHOD("prev"), static_cast<Ref<SetIterator> (SetIterator::*)()>(&SetIterator::prev));
    ClassDB::bind_method(D_METHOD("get_value"), static_cast<Variant (SetIterator::*)()>(&SetIterator::get_value));
}