//
// Created by elmeh on 2025-10-13.
//

#ifndef MYSTL_LIST_H
#define MYSTL_LIST_H

#include <cstddef>
#include <cassert>

template<typename T>
class List {
public:
    struct Node {

        Node():prev(nullptr), next(nullptr) {};
        explicit Node(const T& p_data): data(p_data), prev(nullptr), next(nullptr) {} ;
        T data;
        Node* prev;
        Node* next;
    };

    List();
    size_t taille() const;
    void inserer(size_t pos, const T& data);
    const T& lire(size_t pos) const;

private:
    Node* trouverElementPosition(size_t n) const;
    size_t cardinal;
    Node* head;
    Node* tail;
};

template<typename T>
List<T>::List(): head(new Node), tail(new Node), cardinal(0) {
    head->next = tail;
    tail->prev = head;
}

template<typename T>
size_t List<T>::taille() const {
    return cardinal;
}

template<typename T>
void List<T>::inserer(size_t pos, const T& data) {
    assert(pos <= cardinal);
    auto p =trouverElementPosition(pos);
    auto n = new Node(data);
    p->prev->next = n;
    n->prev = p->prev;
    p->prev = n;
    n->next = p;
    ++cardinal;

    //p = p->next;
    //p->data = data;
}

template<typename T>
const T & List<T>::lire(size_t pos) const {
    assert(pos < cardinal);
    return trouverElementPosition(pos)->data;
}

template<typename T>

List<T>::Node * List<T>::trouverElementPosition(size_t n) const {

    Node* p = head->next;
    for (size_t i = 0; i < n; ++i) {
        p = p->next;
    }
    return p;
}


#endif //MYSTL_LIST_H
