/*#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "Vector.h"


template <class K, class V>
class Map
{
private:

    struct Pair {
        K key;
        V value;

        Pair(){}
        Pair(const K& k, const V& v) : key(k), value(v) {}
    };
    Vector<Pair> elements;

public:
    void insert(const K& k, const V& v)
    {
        for (int i = 0; i < elements.getSize(); i++) {
            if (elements[i].key == k) {
                elements[i].value = v;//update tree
                return;
            }
        }
        elements.addRecord(Pair(k, v));
    }


void setKey(const K& key)
{
    for (int i = 0; i < elements.getSize(); i++) {
        if (elements[i].key == key) {
            return;
        }
    }

    insert(key, V());
}

    V& ValueToSet(const K& key)
    {
        for (int i = 0; i < elements.getSize(); i++) {
            if (elements[i].key == key) {
                return elements[i].value;
            }
        }

    }

    bool contains(const K& key) const
    {
        for (int i = 0; i < elements.getSize(); i++) {
            if (elements[i].key == key) {
                return true;
            }
        }
        return false;
    }

    int getSize() const
    {
        return elements.getSize();
    }

};

#endif // MAP_H_INCLUDED
*/
