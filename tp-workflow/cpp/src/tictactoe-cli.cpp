#include "Tictactoe.hpp"

using namespace std;

int main() {

    Jeu jeu;
    jeu.jouer(0, 1);
    jeu.jouer(1, 2);
    std::cout << jeu << std::endl;

    return 0;
}

