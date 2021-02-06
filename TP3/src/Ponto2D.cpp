#include <iostream>
#include <cmath>
#include <time.h>
#include "Ponto2D.h"

Ponto2D ::Ponto2D()
{
    x = 0;
    y = 0;
    id = getNextid();
}

Ponto2D ::Ponto2D(double xx, double yy)
{
    x = xx;
    y = yy;
    id = getNextid();
}

double Ponto2D ::getX() const
{
    return x;
}

double Ponto2D ::getY() const
{
    return y;
}

int Ponto2D ::getId() const
{
    return id;
}

int Ponto2D ::getNextid()
{
    srand(time(NULL));
    int aleatorio;
    std::map<int, Ponto2D *>::iterator it;
    do
    {
        aleatorio = rand() % 1001;
        it = pontos.find(aleatorio);
    } while (it != pontos.end());

    int id = aleatorio;
    pontos.insert(std::pair<int, Ponto2D *>(id, this));
    return id;
}

Ponto2D ::~Ponto2D()
{
    std::map<int, Ponto2D *>::iterator it;
    it = pontos.find(id);
    pontos.erase(it);
}

double Ponto2D ::distToOrig()
{
    return sqrt(x * x + y * y);
}

double Ponto2D ::distTo(const Ponto2D &p2) const
{
    double x1 = x - p2.getX();
    double y1 = y - p2.getY();
    return sqrt(x1 * x1 + y1 * y1);
}

Ponto2D Ponto2D ::sumPoint(const Ponto2D &p2)
{
    double x1 = x + p2.getX();
    double y1 = y + p2.getY();
    return Ponto2D(x1, y1);
}

void Ponto2D ::sumOf(const Ponto2D &p2)
{
    double x1 = x + p2.getX();
    double y1 = y + p2.getY();
    this->setX(x1);
    this->setY(y1);
}

inline int Ponto2D ::getid() const
{
    return this->id;
}

void Ponto2D ::setX(double x_)
{
    x = x_;
}

void Ponto2D ::setY(double y_)
{
    y = y_;
}

void Ponto2D ::print() const
{
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
