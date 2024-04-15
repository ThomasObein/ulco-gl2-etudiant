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


    // TODO


