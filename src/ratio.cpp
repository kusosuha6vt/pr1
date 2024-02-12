#include "ratio.h"
#include <cmath>
#include <iostream>
#include <numeric>

#ifndef LOG_ENABLED
#define LOG_ENABLED true
#endif

#define LOG(func_name) \
    if (LOG_ENABLED)   \
    std::cerr << func_name << "\n"

Ratio::Ratio() {
    LOG("Ratio()");

    nom = 0;
    denom = 1;
}

Ratio::Ratio(int x, int y) {
    LOG("Ratio(int)");

    nom = x;
    denom = y;
}

Ratio::~Ratio() {
    LOG("~Ratio()");
}

Ratio::Ratio(const Ratio &other) {
    LOG("Ratio(const Ratio &)");

    nom = other.nom;
    denom = other.denom;
}

double Ratio::getValue() const {
    LOG("Ratio::getValue()");

    return static_cast<double>(nom) / denom;
}

void Ratio::operator--() {
    LOG("Ratio::operator--()");

    std::swap(nom, denom);
}

Ratio Ratio::operator&() const {
    LOG("Ratio::operator&()");

    int g = std::gcd(nom, denom);
    Ratio r{nom / g, denom / g};

    // if possible, move sign to nominator
    if (r.denom < 0) {
        r.denom *= -1;
        r.nom *= -1;
    }
    return r;
}

void Ratio::setNom(int x) {
    LOG("Ratio::setNom(int)");

    nom = x;
}

void Ratio::setDenom(int x) {
    LOG("Ratio::setDeom(int)");

    denom = x;
}

int Ratio::getNom() const {
    LOG("Ratio::getNom()");

    return nom;
}

int Ratio::getDenom() const {
    LOG("Ratio::getDenom()");

    return denom;
}

Ratio &Ratio::operator=(const Ratio &other) {
    LOG("Ratio::operator=(const Ratio &other)");

    nom = other.nom;
    denom = other.denom;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Ratio &r) {
    LOG("operator<<(std::ostream &, const Ratio &)");

    out << r.getNom() << "/" << r.getDenom();
    return out;
}

void Ratio::printRectangle() const {
    LOG("Ratio::printRectangle()");

    for (int i = 0; i < std::abs(nom); ++i) {
        for (int j = 0; j < std::abs(denom); ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

double Ratio::len() const {
    LOG("Ratio::len()");

    return std::sqrt(nom * nom + denom * denom);
}

bool Ratio::operator==(const Ratio &other) const {
    Ratio a = &(*this);
    Ratio b = &(other);
    return a.nom == b.nom && a.denom == b.denom;
}
