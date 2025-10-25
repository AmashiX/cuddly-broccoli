//
// Created by elmeh on 2025-10-24.
//

#include <stack>
#include "Digraph.h"

template<typename T>
void aux_dfs_explore(const Digraph<T> &graph, const T& depart, std::stack<T>& abandons, std::unordered_map<T, bool>& sommetDecouvert) {
    sommetDecouvert.at(depart) = true;
    for (auto arc : graph.sommetsAdjacents(depart)) {
        auto voisin = std::get<0>(arc);
        if (sommetDecouvert.at(voisin) == false) aux_dfs_explore(graph, voisin, abandons, sommetDecouvert);
    }
    abandons.push(depart);
}


template<typename T>
std::stack<T> dfs_explore(const Digraph<T> &graph, const T& depart) {
    std::stack<T> abandons;
    std::unordered_map<T, bool> sommetDecouvert;
    for (auto s : graph.enumererSommets()) sommetDecouvert.insert({s, false});
    aux_dfs_explore(graph, depart, abandons, sommetDecouvert);
    return abandons;
}