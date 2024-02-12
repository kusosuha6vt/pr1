#ifndef RATIO_H
#define RATIO_H

#include <iosfwd>

/*
Методы:
- получить частное,
- построить символами прямоугольник со сторонами (числитель х знаменатель),
- найти длину вектора с началом в точке (0,0) и концом в точке (числитель,
знаменатель)

Перегруженные операции:
– унарный префиксный «--»: поменять местами числитель и знаменатель;
– унарный «&»: сократить дробь
*/

class Ratio {
public:
    // Constructor without params
    Ratio();
    // Constructor with 2 parameters
    Ratio(int x, int y = 1);
    // Destructor
    ~Ratio();
    // Copy constructor
    Ratio(const Ratio &other);
    // Copy-assign
    Ratio &operator=(const Ratio &other);

    // quotient
    double getValue() const;

    // print a rectangle of size (nom x denom)
    void printRectangle() const;

    // find a length of vector (nom, denom)
    double len() const;

    bool operator==(const Ratio &other) const;
    // flip nominator and denominator
    void operator--();
    // Resuce the ratio
    Ratio operator&() const;

    // setters and getters
    void setNom(int x);
    void setDenom(int x);
    int getNom() const;
    int getDenom() const;

private:
    int nom, denom;

    friend std::ostream &operator<<(std::ostream &out, const Ratio &r);
};

#endif
