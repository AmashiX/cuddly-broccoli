//
// Created by elmeh on 2025-10-10.
//

#include "Digraph.h"
#include "List.h"
#include "gtest/gtest.h"
#include "Vecteur.h"


TEST(Vecteur, constructeur_vide) {
    Vecteur<int> vecteur;
    EXPECT_EQ(0,vecteur.taille());
}

TEST(Vecteur, inserer_vide_taille_1) {
    Vecteur<int> vecteur;
    vecteur.inserer(0,43);
    EXPECT_EQ(1,vecteur.taille());
}

TEST(Vecteur, supprimer_valeur) {
    Vecteur<int> vecteur;
    vecteur.inserer(0,43);
    vecteur.inserer(1,60);
    vecteur.supprimer(1);
    EXPECT_EQ(43,vecteur.Lire(0));
}


TEST(Vecteur, remplacer_valeur) {
    Vecteur<int> vecteur;
    vecteur.inserer(0,43);
    vecteur.inserer(1,60);
    vecteur.remplacer(1, 11);
    EXPECT_EQ(11,vecteur.Lire(1));
}

TEST(Vecteur, capacite_check) {
    Vecteur<int> vecteur(3);
    vecteur.inserer(0,43);
    vecteur.inserer(1,60);
    vecteur.inserer(2,70);
    vecteur.inserer(3,80);
    EXPECT_EQ(6, vecteur.reqCapacite());
    EXPECT_EQ(4, vecteur.taille());
    EXPECT_EQ(70, vecteur.Lire(2));
}

TEST(List, test_vide_check) {
    List<int> liste;
    EXPECT_EQ(0, liste.taille());
}

TEST(List, inserer_Lire) {
    List<int> liste;
    liste.inserer(0,43);
    liste.inserer(1,60);
    liste.inserer(2,70);
    EXPECT_EQ(70,liste.lire(2));
}

TEST(Digraph, digraph_vide) {
    Digraph<int> digraph;
    EXPECT_EQ(0,digraph.taille());
}

TEST(Digraph, digraph_ajouter_un_lire_un) {
    Digraph<int> digraph;
    digraph.ajoutSommet(33);
    digraph.ajoutSommet(44);
    EXPECT_EQ(2,digraph.taille());
    EXPECT_TRUE(digraph.sommetExists(33));
    EXPECT_FALSE(digraph.sommetExists(333));
}
TEST(Digraph, digraph_deux_sommet) {
    Digraph<int> d;
    d.ajoutSommet(33);
    d.ajoutSommet(44);
    d.ajouterArc(33,44,2);
    EXPECT_TRUE(d.arcExists(33,44));
}