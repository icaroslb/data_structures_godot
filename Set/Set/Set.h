#ifndef SET_H
#define SET_H

#include <rb_tree/rb_tree.h>
#include "SetIterator.h"

class Object;

class Set : public RefCounted {
    GDCLASS(Set, RefCounted);

    static void _bind_methods();

    ds::rb_tree<Variant> _tree;
    Callable _comp;
public:
    Set();
    Set(bool (*comp)(const Variant&, const Variant&));
    Set(const Set& set);

    void init(const Callable &comp);

    bool insert(const Variant &key);
    bool remove(const Variant &key);
    Ref<RefCounted> search(const Variant &key);
    Ref<RefCounted> begin();
    Ref<RefCounted> end();
    Ref<RefCounted> nil();
    size_t get_size();
};

#endif // SET_H