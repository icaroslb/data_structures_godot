#ifndef SET_GODOT_H
#define SET_GODOT_H

#include <rb_tree/rb_tree.h>
#include "SetIterator.h"
#include "SetrIterator.h"

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

    Ref<SetrIterator> rbegin();
    Ref<SetrIterator> rend();
    Ref<SetrIterator> rnil();
    size_t get_size();
    size_t get_size_2(float test);
    size_t get_size(int test);

    SetIterator _search(const Variant &key);
    SetIterator _begin();
    SetIterator _end();
    SetIterator _nil();
};

#endif // SET_H