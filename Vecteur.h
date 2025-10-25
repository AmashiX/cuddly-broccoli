//
// Created by elmeh on 2025-10-10.
//

#ifndef MYSTL_VECTEUR_H
#define MYSTL_VECTEUR_H

#include <cstddef>
//#include <stdexcept>
#include <cassert>

template <typename T>
class Vecteur {

public:
   explicit Vecteur(size_t p_capacite = DEF_CAPACITE);

    void inserer(size_t index, const T& nouveau);

    T Lire(size_t index) const;

    const size_t &taille() const;

    void supprimer(size_t index);

    void remplacer(size_t index, const T& nouveau);

    void reallouer();

    size_t reqCapacite() const;

    bool invariant() const;



private:
    static const size_t DEF_CAPACITE = 10;
    T* adresse;
    size_t cardinal;
    size_t m_capacite;
};



template<typename T>
Vecteur<T>::Vecteur(size_t p_capacite) : m_capacite(p_capacite),adresse(new T[p_capacite]) , cardinal(0) {

}



template <typename T>
const size_t &Vecteur<T>::taille() const {
    return cardinal;
}

template<typename T>
void Vecteur<T>::supprimer(size_t index) {

        for (size_t i = index; i < cardinal-1; ++i) adresse[i] = adresse[i+1];
        --cardinal;

    assert(invariant());
}

template <typename T>
void Vecteur<T>::inserer(size_t index, const T& nouveau) {

    assert(index <= cardinal);
    //
    if (cardinal == m_capacite) reallouer();
    for (size_t i= cardinal; i>index; --i) adresse[i] = adresse[i-1];
    adresse[index] = nouveau;
    ++cardinal;

    assert(invariant());
}


template<typename T>
T Vecteur<T>::Lire(size_t index) const {

    assert(index < cardinal);
    return adresse[index];
}

template<typename T>
void Vecteur<T>::remplacer(size_t index, const T& nouveau) {
    assert(index <= cardinal);
    adresse[index] = nouveau;

    assert(invariant());
}

template<typename T>
void Vecteur<T>::reallouer() {
    //
    T* backup = new T[m_capacite];
    for (size_t i = 0; i < cardinal; ++i) backup[i] = adresse[i];
    delete[] adresse;
    m_capacite *= 2;
    adresse = new T[m_capacite];
    for (size_t i = 0; i < cardinal; ++i) adresse[i] = backup[i];


}

template<typename T>
size_t Vecteur<T>::reqCapacite() const {
    return m_capacite;
}

template<typename T>
bool Vecteur<T>::invariant() const {
    if (adresse == nullptr) return false;
    if (m_capacite == 0) return false;
    return cardinal <= m_capacite;
}


#endif //MYSTL_VECTEUR_H
