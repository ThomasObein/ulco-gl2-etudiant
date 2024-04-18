#include "Tictactoe.hpp"
#include <iostream>

using namespace std;

std::string get_current_player(const Jeu &jeu) {
    std::string current_player_text;
    switch (jeu.getStatus())
    {
    case Status::RougeJoue:
        current_player_text = "[ROUGE]";
        break;
    case Status::VertJoue:
        current_player_text = "[VERT]";
    }
    return current_player_text;
}

void demander_coup(Jeu &jeu) {
    std::string line_input;
    std::string column_input;

    std::string current_player_text = get_current_player(jeu);

    // Entrée d'un coup
    int line, column;
    bool first_try = true;
    while (!jeu.jouer(line - 1, column - 1)) {
        try {
            if (!first_try) std::cout << "Coup invalide (case non vide ou numéro de ligne/colonne hors de la plage)" << std::endl;
            std::cout << current_player_text << " Entrez un numéro de ligne (1/2/3): ";
            std::getline(std::cin, line_input);
            std::cout << current_player_text << " Entrez un numéro de colonne (1/2/3): ";
            std::getline(std::cin, column_input);
            line = stoi(line_input);
            column = stoi(column_input);
            first_try = false;
        } catch (...) {
            std::cout << "Entrée invalide.";
        }
    }
}

int main() {

    Jeu jeu;
    while (!jeu.isGameFinished()) {
        demander_coup(jeu); 
        std::cout << jeu << std::endl;
    }

    std::string game_state;
    switch (jeu.getStatus())
    {
    case Status::Egalite:
        game_state = "égalité";
        break;
    case Status::RougeGagne:
        game_state = "victoire de rouge";
        break;
    case Status::VertGagne:
        game_state = "victoire de vert";
        break;
    }

    std::cout << "Partie terminée: " << game_state << std::endl;

    return 0;
}

