#include "Forme.hpp"
#include <math.h>

Disque::Disque(double rayon) :
    _rayon(rayon)
{}

double Disque::aire() const {
    return M_PI * 2 * _rayon;
}

Description Disque::toDescription() const {
    Description desc;
    desc["name"] = "Disque";
    desc["rayon"] = std::to_string(_rayon);
    return desc;
}

Rectangle::Rectangle(double largeur, double hauteur) :
    _largeur(largeur), _hauteur(hauteur)
{}

double Rectangle::aire() const {
    return _largeur * _hauteur;
}

Description Rectangle::toDescription() const {
    Description desc;
    desc["name"] = "Rectangle";
    desc["largeur"] = std::to_string(_largeur);
    desc["hauteur"] = std::to_string(_hauteur);
    return desc;
}