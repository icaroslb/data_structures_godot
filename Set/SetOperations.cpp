#include "SetGodot/SetOperations.h"

#include <algorithm>

Ref<Set> SetOperations::union_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp) {
    Ref<Set> result;

    result.instantiate();
    result->init(comp);

    std::for_each(set_0->_begin(), set_0->_end(), [&] (const Variant& value) {
        result->insert(value);
    });

    std::for_each(set_1->_begin(), set_1->_end(), [&] (const Variant& value) {
        result->insert(value);
    });

    return result;
}

Ref<Set> SetOperations::intersection_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp) {
    Ref<Set> result;

    result.instantiate();
    result->init(comp);

    std::for_each(set_0->_begin(), set_0->_end(), [&] (const Variant& value) {
        if (set_1->_search(value) != set_1->_nil()) {
            result->insert(value);
        }
    });

    std::for_each(set_1->_begin(), set_1->_end(), [&] (const Variant& value) {
        if (set_0->_search(value) != set_0->_nil()) {
            result->insert(value);
        }
    });

    return result;
}

Ref<Set> SetOperations::diference_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp) {
    Ref<Set> result;

    result.instantiate();
    result->init(comp);

    std::for_each(set_0->_begin(), set_0->_end(), [&] (const Variant& value) {
        if (set_1->_search(value) == set_1->_nil()) {
            result->insert(value);
        }
    });

    return result;
}

Ref<Set> SetOperations::xor_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp) {
    Ref<Set> result;

    result.instantiate();
    result->init(comp);

    std::for_each(set_0->_begin(), set_0->_end(), [&] (const Variant& value) {
        if (set_1->_search(value) == set_1->_nil()) {
            result->insert(value);
        }
    });

    std::for_each(set_1->_begin(), set_1->_end(), [&] (const Variant& value) {
        if (set_0->_search(value) == set_0->_nil()) {
            result->insert(value);
        }
    });

    return result;
}

void SetOperations::_bind_methods() {
    ClassDB::bind_static_method("SetOperations", D_METHOD("union_op"       , "set_0", "set_1", "comp"), static_cast<Ref<Set> (*)(const Ref<Set> , const Ref<Set> , const Callable&)>(&SetOperations::union_op));
    ClassDB::bind_static_method("SetOperations", D_METHOD("intersection_op", "set_0", "set_1", "comp"), static_cast<Ref<Set> (*)(const Ref<Set> , const Ref<Set> , const Callable&)>(&SetOperations::intersection_op));
    ClassDB::bind_static_method("SetOperations", D_METHOD("diference_op"   , "set_0", "set_1", "comp"), static_cast<Ref<Set> (*)(const Ref<Set> , const Ref<Set> , const Callable&)>(&SetOperations::diference_op));
    ClassDB::bind_static_method("SetOperations", D_METHOD("xor_op"         , "set_0", "set_1", "comp"), static_cast<Ref<Set> (*)(const Ref<Set> , const Ref<Set> , const Callable&)>(&SetOperations::xor_op));
}