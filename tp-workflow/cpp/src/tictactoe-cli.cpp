#include "Tictactoe.hpp"
#include <iostream>

using namespace std;

void demander_coup(Jeu &jeu) {
    std::string line_input;
    std::string column_input;

    // Affichage du joueur en cours
    std::string current_player_text;
    switch (jeu.getStatus())
    {
    case Status::RougeJoue:
        current_player_text = "[ROUGE]";
        break;
    case Status::VertJoue:
        current_player_text = "[VERT]";
    }

    // Entrée d'un coup
    int line, column;
    while (!jeu.jouer(line - 1, column - 1)) {
        try {
            std::cout << current_player_text << " Entrez un numéro de ligne (1/2/3): ";
            std::getline(std::cin, line_input);
            std::cout << current_player_text << " Entrez un numéro de colonne (1/2/3): ";
            std::getline(std::cin, column_input);
            line = stoi(line_input);
            column = stoi(column_input);
        } catch (...) {
            std::cout << "Entrée invalide.";
        }
    }
}

int main() {

    Jeu jeu;
    demander_coup(jeu);

    std::cout << jeu << std::endl;

    return 0;
}

