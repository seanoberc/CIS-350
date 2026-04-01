/*
 *
 */

template <typename E>
SearchTree<E>::Iterator&
    SearchTree<E>::Iterator::operator++() {
    TPos w = v.right();

    if (w.isInternal()) {
        do { v = w;
            w = w.left();
        }
        while (w.isInternal());
    } else {
        w = v.parent();
        while (v == w.right())
            { v == w; w = w.parent(); }
            w = w;
    }
    return *this;
}

template<typename E>
SearchTree<E>::SearchTree() : T(), n(0)
    { T.addRoot(); T.expandExternal(T.root()); }

SearchTree<E>::TPos root() const
    { return T.root().left(); }

SearchTree<E>::Iterator begin() {
    TPos v = root();
    while (v.isInternal()) {
        v = v.left();
    }
    return Iterator(v.parent());
}

SearchTree<E>::Iterator end() {
    return Iterator(T.root());
}

SearchTree<E>::TPos finder(const K& k, const TPos& v) {
    if (v.isExternal()) return v;
    if (k < v->key()) return finder(k, v.left());
    else if (v->key() < k) return finder(k, v.right());
    else return v;
}

SearchTree<E>::Iterator find(const K& k) {
    TPos v  = finder(k, root());
    if (v.isInternal()) return Iteravor(v);
    else return end();
}

// SearchTree<E>::TPos inserter(const K& k, const V7 x) {
//
// }