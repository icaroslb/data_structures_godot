#ifndef SET_OPERATIONS_H
#define SET_OPERATIONS_H

#include "Set.h"

#include "core/object/object.h"

class SetOperations : public Object {
    GDCLASS(SetOperations, Object);

    static void _bind_methods();
public:
    static Ref<Set> union_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp);
    static Ref<Set> intersection_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp);
    static Ref<Set> diference_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp);
    static Ref<Set> xor_op(const Ref<Set> set_0, const Ref<Set> set_1, const Callable &comp);
};

#endif // SET_OPERATIONS_H