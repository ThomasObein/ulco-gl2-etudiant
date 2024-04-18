#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    return _status;
}

bool Jeu::areCoordsValid(int i, int j) const {
    return (i >= 0 && i < 3 && j >= 0 && j < 3);
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
            if (hasVictory(Cell::Rouge)) _status = Status::RougeGagne;
            else _status = Status::VertJoue;
            break;
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;
            if (hasVictory(Cell::Vert)) _status = Status::VertGagne;
            else _status = Status::RougeJoue;
            break;
        default:
            break;
        }

        if (!isGameFinished() && isGameDraw()) {
            _status = Status::Egalite;
        }
        return true;
    }
    return false;
}

bool Jeu::isGameFinished() {
    return _status == Status::VertGagne || _status == Status::RougeGagne || _status == Status::Egalite;
}

bool Jeu::isGameDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (getCell(i, j) == Cell::Vide) {
                return false;
            }
        }
    }
    return true;
}

bool Jeu::hasVictory(Cell cellType) {

    for (int i = 0; i < 3; i++) {
        if (getCell(i, 0) == cellType && getCell(i, 1) == cellType && getCell(i, 2) == cellType) return true;
        if (getCell(0, i) == cellType && getCell(1, i) == cellType && getCell(2, i) == cellType) return true;
    }

    // Diagonales
    if (getCell(0, 0) == cellType && getCell(1, 1) == cellType && getCell(2, 2) == cellType) return true;
    if (getCell(0, 2) == cellType && getCell(1, 1) == cellType && getCell(2, 0) == cellType) return true;

    return false;
}

void Jeu::raz() {
    _status = Status::RougeJoue;
    for (int i = 0; i < 3; i++) {
        _plateau[i].fill(Cell::Vide);
    }
}

