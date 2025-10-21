//
// Created by elmeh on 2025-10-20.
//

#ifndef MYSTL_DIGRAPH_H
#define MYSTL_DIGRAPH_H
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>

template <typename T>
class Digraph {
    public:
    Digraph();
    void ajoutSommet(const T& sommet);
    void supprimerSommet(const T& sommet);
    void ajouterArc(const T& depart, const T& arrivee, double poids = 0.0);
    void supprimerArc(const T& depart, const T& arrivee);
    size_t taille() const;
    size_t trouverNumeroSommet(const T& sommet) const;

    bool sommetExists(const T& sommet) const;
    bool arcExists(const T& depart, const T& arrivee) const;


private:
    struct Arc {
        size_t destination; // numero de sommet d'arrivé
        double poids;
        Arc(size_t p_destination, double p_poids) : destination(p_destination), poids(p_poids) {}
        bool operator == (size_t n) const {return destination == n;}
    };

    bool invariant() const;
    std::vector<T> index;
    std::vector<std::list<Arc>> listes;
};

template<typename T>
Digraph<T>::Digraph(): index(), listes() {
    assert(invariant());
}

template<typename T>
void Digraph<T>::ajoutSommet(const T &sommet) {
    assert(!sommetExists(sommet));
    index.push_back(sommet);
    listes.emplace_back();
    assert(invariant());
}

template<typename T>
void Digraph<T>::ajouterArc(const T &depart, const T &arrivee, double poids) {
    assert(sommetExists(depart));
    assert(sommetExists(arrivee));
    size_t ndep = trouverNumeroSommet(depart);
    size_t narr = trouverNumeroSommet(arrivee);
    listes.at(ndep).emplace_back(narr, poids);

}

template<typename T>
size_t Digraph<T>::taille() const {
    return index.size();
}

template<typename T>
size_t Digraph<T>::trouverNumeroSommet(const T &sommet) const {
    auto it = std::find(index.begin(), index.end(), sommet);
    return std::distance(index.begin(), it);
}

template<typename T>
bool Digraph<T>::sommetExists(const T &sommet) const {
    auto it = std::find(index.begin(), index.end(), sommet);
    if (it != index.end()) return true;
    return false;
}

template<typename T>
bool Digraph<T>::arcExists(const T &depart, const T &arrivee) const {
    auto ndep = trouverNumeroSommet(depart);
    auto narr = trouverNumeroSommet(arrivee);
    auto l = listes.at(ndep);
    auto it = std::find(l.begin(), l.end(), narr);
    if (it != l.end()) return true;
    return false;
}


template<typename T>
bool Digraph<T>::invariant() const {
    if (index.size() != listes.size()) return false;
    return true;
}


#endif //MYSTL_DIGRAPH_H
