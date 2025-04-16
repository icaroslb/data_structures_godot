#include "SetGodot/Set.h"

Set::Set()
: _tree() {}

Set::Set(const Callable &comp)
: _tree(
    [comp] (const Variant& v0, const Variant &v1) -> bool {
        Variant result = comp.call(v0, v1);

        return result.operator bool();
    }) {}

Set::Set(const Set& set)
: _tree(set._tree) {}

void Set::init(const Callable &comp) {
    auto lambda = [comp] (const Variant& v0, const Variant &v1) -> bool {
        Variant result = comp.call(v0, v1);

        return result.operator bool();
    };

    _tree.initialize(lambda);
}

bool Set::insert(const Variant &key) {
    return _tree.insert(key);
}

bool Set::remove(const Variant &key) {
    return _tree.remove(key);
}

Ref<SetIterator> Set::search(const Variant &key) {
    Ref<SetIterator> iterator;
    iterator.instantiate(_tree.search(key));
    return iterator;
}

Ref<SetIterator> Set::begin() {
    Ref<SetIterator> iterator;
    iterator.instantiate(_tree.begin());
    return iterator;
}

Ref<SetIterator> Set::end() {
    Ref<SetIterator> iterator;
    iterator.instantiate(_tree.end());
    return iterator;
}

Ref<SetIterator> Set::nil() {
    Ref<SetIterator> iterator;
    iterator.instantiate(_tree.nil());
    return iterator;
}

size_t Set::get_size() {
    return _tree.get_size();
}

SetIterator Set::_search(const Variant &key) {
    return _tree.search(key);
}

SetIterator Set::_begin() {
    return _tree.begin();
}

SetIterator Set::_end() {
    return _tree.end();
}

SetIterator Set::_nil() {
    return _tree.nil();
}

void Set::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init", "comparison_func"), static_cast<void (Set::*)(const Callable&)>(&Set::init));
    ClassDB::bind_method(D_METHOD("insert", "key"), static_cast<bool (Set::*)(const Variant&)>(&Set::insert));
    ClassDB::bind_method(D_METHOD("remove", "key"), static_cast<bool (Set::*)(const Variant&)>(&Set::remove));

    ClassDB::bind_method(D_METHOD("search", "key"), static_cast<Ref<SetIterator> (Set::*)(const Variant&)>(&Set::search));

    ClassDB::bind_method(D_METHOD("begin"), static_cast<Ref<SetIterator> (Set::*)()>(&Set::begin));

    ClassDB::bind_method(D_METHOD("end"), static_cast<Ref<SetIterator> (Set::*)()>(&Set::end));

    ClassDB::bind_method(D_METHOD("nil"), static_cast<Ref<SetIterator> (Set::*)()>(&Set::nil));

    ClassDB::bind_method(D_METHOD("get_size"), static_cast<size_t (Set::*)()>(&Set::get_size));
}