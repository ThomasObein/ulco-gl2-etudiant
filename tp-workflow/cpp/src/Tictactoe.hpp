#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <array>
#include <iostream>

/// @brief Enumération des status du jeu
enum class Status { Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue };

/// @brief Enumération des états posibles pour une cellule
enum class Cell { Vide, Rouge, Vert };

/// Moteur de jeu de tictactoe.
class Jeu {
    private:
        std::array<std::array<Cell, 3>, 3> _plateau;
        Status _status;
        /// Retourne True si les coordonnées sont valides
        bool areCoordsValid(int i, int j) const;

        /// @brief Retourne True si la case est vide et a des coordonnées valides
        /// @param i 
        /// @param j 
        /// @return 
        bool isCellFree(int i, int j);

        bool hasVictory(Cell cellType);

        bool isGameDraw();

    public:
        /// Constructeur à utiliser.
        Jeu();

        /// Retourne le status du jeu courant (Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue).
        Status getStatus() const;

        /// Retourne l'état d'une case du plateau
        Cell getCell(int i, int j) const;

        /// Retourne true si la partie est terminée, false sinon
        bool isGameFinished();

        /// Joue un coup pour le joueur courant.
        /// 
        /// i ligne choisie (0, 1 ou 2)
        /// j colonne choisie (0, 1 ou 2)
        /// 
        /// Si le coup est invalide, retourne false. Si le coup est valide,
        /// joue le coup et retourne true.
        bool jouer(int i, int j);

        /// Réinitialise le jeu.
        void raz();
};

std::ostream & operator<<(std::ostream & os, const Jeu & jeu);

#endif

