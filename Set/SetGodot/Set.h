#ifndef SET_H
#define SET_H

#include <rb_tree/rb_tree.h>
#include "SetIterator.h"

class Set : public RefCounted {
    GDCLASS(Set, RefCounted);

    static void _bind_methods();

    ds::rb_tree<Variant> _tree;
    Callable _comp;
public:
    Set();
    Set(const Callable &comp);
    Set(const Set& set);

    void init(const Callable &comp);

    bool insert(const Variant &key);
    bool remove(const Variant &key);
    Ref<SetIterator> search(const Variant &key);
    Ref<SetIterator> begin();
    Ref<SetIterator> end();
    Ref<SetIterator> nil();
    size_t get_size();

    SetIterator _search(const Variant &key);
    SetIterator _begin();
    SetIterator _end();
    SetIterator _nil();
};

#endif // SET_H