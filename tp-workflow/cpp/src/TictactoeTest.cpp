#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("test getCell valid coords") {
    Jeu jeu;
    REQUIRE(jeu.getCell(0, 2) == Cell::Vide);
}


TEST_CASE("test getCell invalid coords") {
    Jeu jeu;
    REQUIRE_THROWS_AS(jeu.getCell(3, 4), std::exception);
}

TEST_CASE("test raz constructeur") { 
    Jeu jeu;
    bool empty = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jeu.getCell(i, j) != Cell::Vide) {
                empty = false;
                break;
            }
        }
    }
    REQUIRE(empty);
}

TEST_CASE("test affichage (jeu vide)") {
    Jeu jeu;
    std::ostringstream output;
    output << jeu;

    std::string valid_output = "...\n...\n...\n";
    REQUIRE(output.str() == valid_output);
}

TEST_CASE("test jouer (1 tour)") {
    Jeu jeu;
    bool succes = jeu.jouer(0, 2);
    REQUIRE(succes);
    REQUIRE(jeu.getCell(0, 2) == Cell::Rouge);
}

TEST_CASE("test jouer (2 tours, 2 cases différentes)") {
    Jeu jeu;
    bool succes1 = jeu.jouer(0, 2);
    REQUIRE(succes1);
    REQUIRE(jeu.getCell(0, 2) == Cell::Rouge);

    bool succes2 = jeu.jouer(2, 1);
    REQUIRE(succes2);
    REQUIRE(jeu.getCell(2, 1) == Cell::Vert);
}

TEST_CASE("test jouer (2 tours, 2 cases identiques)") {
    Jeu jeu;
    bool succes1 = jeu.jouer(0, 2);
    REQUIRE(succes1);
    REQUIRE(jeu.getCell(0, 2) == Cell::Rouge);

    bool succes2 = jeu.jouer(0, 2);
    REQUIRE(!succes2);
    REQUIRE(jeu.getCell(0, 2) == Cell::Rouge);
}

TEST_CASE("test victoire rouge ligne 2") {
    Jeu jeu;

    jeu.jouer(1, 0);
    jeu.jouer(0, 1);
    jeu.jouer(1, 1);
    jeu.jouer(2, 1);
    jeu.jouer(1, 2);

    REQUIRE(jeu.getStatus() == Status::RougeGagne);
}

TEST_CASE("test victoire vert ligne 3") {
    Jeu jeu;

    jeu.jouer(1, 0);
    jeu.jouer(2, 0);
    jeu.jouer(1, 2);
    jeu.jouer(2, 1);
    jeu.jouer(0, 2);
    jeu.jouer(2, 2);

    REQUIRE(jeu.getStatus() == Status::VertGagne);
}

TEST_CASE("test victoire rouge colonne 1") {
    Jeu jeu;

    jeu.jouer(0, 0);
    jeu.jouer(2, 0);
    jeu.jouer(0, 1);
    jeu.jouer(1, 1);
    jeu.jouer(0, 2);

    REQUIRE(jeu.getStatus() == Status::RougeGagne);
}


TEST_CASE("test victoire vert colonne 3") {
    Jeu jeu;

    jeu.jouer(1, 0);
    jeu.jouer(2, 0);
    jeu.jouer(0, 1);
    jeu.jouer(2, 1);
    jeu.jouer(0, 2);
    jeu.jouer(2, 2);

    REQUIRE(jeu.getStatus() == Status::VertGagne);
}

TEST_CASE("test victoire rouge diagonale gauche droite") {
    Jeu jeu;

    jeu.jouer(0, 0);
    jeu.jouer(2, 0);
    jeu.jouer(1, 1);
    jeu.jouer(2, 1);
    jeu.jouer(2, 2);

    REQUIRE(jeu.getStatus() == Status::RougeGagne);
}

TEST_CASE("test victoire vert diagonale droite gauche") {
    Jeu jeu;

    jeu.jouer(0, 0);
    jeu.jouer(0, 2);
    jeu.jouer(0, 1);
    jeu.jouer(1, 1);
    jeu.jouer(2, 2);
    jeu.jouer(2, 0);

    REQUIRE(jeu.getStatus() == Status::VertGagne);
}

TEST_CASE("test egalite") {
    Jeu jeu;

    jeu.jouer(0, 0); 
    jeu.jouer(0, 2); 
    jeu.jouer(0, 1); 
    jeu.jouer(1, 0);
    jeu.jouer(1, 1); 
    jeu.jouer(2, 2);
    jeu.jouer(1, 2);
    jeu.jouer(2, 1);
    jeu.jouer(2, 0);

    REQUIRE(jeu.getStatus() == Status::Egalite);
}