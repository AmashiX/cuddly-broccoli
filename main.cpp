#include <iostream>
#include <vector>
#include <list>
#include "Vecteur.h"

int main() {
    //std::vector<int> v = {1,2,3};

    //Vecteur<int> vecteur;
    //vecteur.inserer(0,43);

    std::list<int> l = {1,2,3};

    for (auto i : l) {
        std::cout << i;
    }
    return 0;
}