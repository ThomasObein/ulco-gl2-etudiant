#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    // TODO
    return Status::RougeJoue;
}

bool Jeu::areCoordsValid(int i, int j) const {
    return (i >= 0 && i < _plateau.size() && j >= 0 && j < _plateau.size());
}

Cell Jeu::getCell(int i, int j) const {
    if (areCoordsValid(i, j)) return _plateau[i][j];
    throw std::exception();
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for (int i = 0; i < jeu._plateau.size(); i++) {
        for (int j = 0; j < jeu._plateau.size(); j++) {
            auto cell = jeu.getCell(i, j);
            switch (cell)
            {
            case Cell::Rouge:
                os << "R";
                break;
            case Cell::Vert:
                os << "V";
                break;
            default:
                os << ".";
                break;
            }
        }
        os << std::endl;
    }
    return os;
}


bool Jeu::jouer(int i, int j) {
    // TODO
    return false;
}

void Jeu::raz() {
    for (int i = 0; i < _plateau.size(); i++) {
        _plateau[i].fill(Cell::Vide);
    }
}

