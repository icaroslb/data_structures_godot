#include "SetGodot/SetrIterator.h"

SetrIterator::SetrIterator() : _iterator() {}

SetrIterator::SetrIterator(const ds::rb_tree<Variant>::rIterator& iterator) : _iterator(iterator) {}

SetrIterator::SetrIterator(const SetrIterator& iterator) : _iterator(iterator._iterator) {}

bool SetrIterator::is_nil() {
    return _iterator.is_nil();
}

Ref<SetrIterator> SetrIterator::next() {
    ++_iterator;
    return Ref<SetrIterator>(this);
}


Ref<SetrIterator> SetrIterator::prev() {
    --_iterator;
    return Ref<SetrIterator>(this);
}

Variant SetrIterator::get_value() {
    return *_iterator;
}

Ref<SetrIterator> SetrIterator::operator++() {
    ++_iterator;

    return Ref<SetrIterator>(this);
}

Ref<SetrIterator> SetrIterator::operator--() {
    --_iterator;
    
    return Ref<SetrIterator>(this);
}

Ref<SetrIterator> SetrIterator::operator++(int) {
    Ref<SetrIterator> old_iterator;
    old_iterator.instantiate(*this);

    _iterator++;

    return old_iterator;
}

Ref<SetrIterator> SetrIterator::operator--(int) {
    Ref<SetrIterator> old_iterator;
    old_iterator.instantiate(*this);

    _iterator--;

    return old_iterator;
}

const Variant& SetrIterator::operator*() {
    return *_iterator;
}

const Variant* SetrIterator::operator->() {
    return _iterator.operator->();
}

bool SetrIterator::operator==(const SetrIterator& iterator) {
    return _iterator == iterator._iterator;
}

bool SetrIterator::operator!=(const SetrIterator& iterator) {
    return _iterator != iterator._iterator;
}

void SetrIterator::_bind_methods() {
    ClassDB::bind_method(D_METHOD("is_nil"), static_cast<bool (SetrIterator::*)()>(&SetrIterator::is_nil));
    ClassDB::bind_method(D_METHOD("next"), static_cast<Ref<SetrIterator> (SetrIterator::*)()>(&SetrIterator::next));
    ClassDB::bind_method(D_METHOD("prev"), static_cast<Ref<SetrIterator> (SetrIterator::*)()>(&SetrIterator::prev));
    ClassDB::bind_method(D_METHOD("get_value"), static_cast<Variant (SetrIterator::*)()>(&SetrIterator::get_value));
}