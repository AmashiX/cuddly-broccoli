//
// Created by elmeh on 2025-10-20.
//

#ifndef MYSTL_DIGRAPH_H
#define MYSTL_DIGRAPH_H
#include <algorithm>
#include <list>
#include <vector>
#include <cassert>
#include <unordered_map>

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

    std::unordered_map<T,double>sommetsAdjacents(const T& depart) const;
    const std::vector<T>&  enumererSommets() const;


private:
    struct Arc {
        size_t destination; // numero de sommet d'arrivé
        double poids;
        Arc(size_t p_destination, double p_poids) : destination(p_destination), poids(p_poids) {}
        bool operator == (size_t n) const {return destination == n;}
    };

    bool invariant() const;
    std::vector<T> sommets;
    std::vector<std::list<Arc>> listes;
};

template<typename T>
Digraph<T>::Digraph(): sommets(), listes() {
    assert(invariant());
}

template<typename T>
void Digraph<T>::ajoutSommet(const T &sommet) {
    assert(!sommetExists(sommet));
    sommets.push_back(sommet);
    listes.emplace_back();
    assert(invariant());
}

template<typename T>
void Digraph<T>::supprimerSommet(const T &sommet) {
    assert(sommetExists(sommet));
    auto numeroSommet = trouverNumeroSommet(sommet);
    sommets.erase(sommets.begin() + numeroSommet);
    listes.erase(listes.begin()+numeroSommet);
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
void Digraph<T>::supprimerArc(const T &depart, const T &arrivee) {
    assert(arcExists(depart,arrivee));
    auto ndep = trouverNumeroSommet(depart);
    auto narr = trouverNumeroSommet(arrivee);
    auto& l = listes.at(ndep);
    auto it = std::find(l.begin(), l.end(), narr);
    l.erase(it);
    assert(invariant());
}

template<typename T>
size_t Digraph<T>::taille() const {
    return sommets.size();
}

template<typename T>
size_t Digraph<T>::trouverNumeroSommet(const T &sommet) const {
    auto it = std::find(sommets.begin(), sommets.end(), sommet);
    return std::distance(sommets.begin(), it);
}

template<typename T>
bool Digraph<T>::sommetExists(const T &sommet) const {
    auto it = std::find(sommets.begin(), sommets.end(), sommet);
    if (it != sommets.end()) return true;
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
std::unordered_map<T, double> Digraph<T>::sommetsAdjacents(const T &depart) const {
    assert(sommetExists(depart));
    std::unordered_map<T, double> voisins;
    auto ndep = trouverNumeroSommet(depart);
    for (auto arc : listes.at(ndep)) voisins.insert({sommets.at(arc.destination), arc.poids});
    return voisins;
}

template<typename T>
const std::vector<T> & Digraph<T>::enumererSommets() const {
    return sommets;
}


template<typename T>
bool Digraph<T>::invariant() const {
    if (sommets.size() != listes.size()) return false;
    return true;
}


#endif //MYSTL_DIGRAPH_H
