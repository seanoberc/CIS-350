#ifndef ASSIGNMENT_5_SEARCHTREE_H
#define ASSIGNMENT_5_SEARCHTREE_H

/*
 *
 */

template <typename E>
class SearchTree {
public:
    typedef typename E::Key K;
    typedef typename E::Value V;
    class Iterator;
public:
    SearchTree();
    int size() const;
    bool empty() const;
    Iterator find(const K& k);
    Iterator insert(const K& k, const V& x);
    void erase(const K& k) throw(NonexistentElement);
    void erase(const Iterator& p);
    Iterator begin();
    Iterator end;
protected:
    typedef BinaryTree<E> BinaryTree;
    typedef typename BinaryTree::Position TPos;
    TPos root() const;
    TPos finder(const K& k, const TPos& v);
    TPos inserter(const K& k, const V& x);
    TPos eraser(TPos& v);
    TPos restructure(const TPos& v)
        throw(BoundaryViolation);
private:
    BinaryTree T;
    int n;
public:
    class Iterator {
    private:
        TPos v;
    public:
        Iterator(const TPos& vv) : v(vv) { }
        const E& operator*() const { return *v; }
        E& operator*() { return *v; }
        bool operator==(const Iterator &) const {
            return v == p.v;
        }
        Iterator& operator++();
        friend class SearchTree;
    };
};

#include "SearchTree.tpp"

#endif //ASSIGNMENT_5_SEARCHTREE_H
