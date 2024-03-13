#pragma once

#include "Descriptible.hpp"

class Forme : virtual public Descriptible {
    public:
        virtual ~Forme() = default;
        virtual double aire() const = 0;
};

class Disque : public Forme {
    public:
        double _rayon;
        Disque(double rayon);
        virtual double aire() const override;
        virtual Description toDescription() const override;
};

class Rectangle : public Forme {
    public:
        double _largeur;
        double _hauteur;
        Rectangle(double largeur, double hauteur);
        virtual double aire() const override;
        virtual Description toDescription() const override;
};

