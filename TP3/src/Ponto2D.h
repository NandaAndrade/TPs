#include <iostream>
#include <map>
class Ponto2D;

std::map<int, Ponto2D *> pontos;
class Ponto2D
{
private:
    double x;
    double y;
    int id;
    int getNextid();

public:
    Ponto2D();
    Ponto2D(double a, double b = 0);
    ~Ponto2D(); //decrementar o id
    double getX() const;
    double getY() const;
    void setX(double x); //inline não funciona
    void setY(double y);
    void print() const;
    double distToOrig();
    double distTo(const Ponto2D &p2) const;
    void virtual sumOf(const Ponto2D &p2);
    Ponto2D sumOf(const Ponto2D &p2);
    int getid() const;
    // Ponto2D sumPoint(Ponto2D);
};
