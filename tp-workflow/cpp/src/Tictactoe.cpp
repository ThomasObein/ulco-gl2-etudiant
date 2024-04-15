#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    return _status;
}

bool Jeu::areCoordsValid(int i, int j) const {
    return (i >= 0 && i < _plateau.size() && j >= 0 && j < _plateau.size());
}

Cell Jeu::getCell(int i, int j) const {
    if (areCoordsValid(i, j)) return _plateau[i][j];
    throw std::exception();
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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

bool Jeu::isCellFree(int i, int j) {
    if (!areCoordsValid(i, j)) return false;
    return (getCell(i, j) == Cell::Vide);
}

bool Jeu::jouer(int i, int j) {
    if (isCellFree(i, j)) {
        Status status = getStatus();
        switch (status)
        {
        case Status::RougeJoue:
            _plateau[i][j] = Cell::Rouge;
            break;
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;
            break;
        }
        updateStatus();
    }
    return false;
}

void Jeu::updateStatus() {
    // TODO: check victoire

    _status = _status == Status::RougeJoue ? Status::VertJoue : Status::RougeJoue;
}

void Jeu::raz() {
    _status = Status::RougeJoue;
    for (int i = 0; i < _plateau.size(); i++) {
        _plateau[i].fill(Cell::Vide);
    }
}

