#include <iostream>
#include <cmath>
#include "Ponto2D.h"

Ponto2D :: Ponto2D(){
    x = 0;
    y = 0;
}

Ponto2D :: Ponto2D(double xx, double yy){
    x = xx;
    y = yy;
}

int Ponto2D :: getNextid(){
    //Trocar por Map
    return id;
}

Ponto2D :: ~Ponto2D(){
    //Algo relacionado com Map.
}

double Ponto2D :: distToOrig(){
    return sqrt(x*x + y*y);
}

double Ponto2D :: distTo(const Ponto2D& p2) const{
    double x1 = x - p2.getX();
    double y1 = y - p2.getY();
    return sqrt (x1*x1 + y1*y1);
}

Ponto2D Ponto2D :: sumOf(const Ponto2D& p2){
    double x1 = x + p2.getX();
    double y1 = y + p2.getY();
    return Ponto2D (x1,y1);
}

//Ponto2D sumPoint(const Ponto2D& p2){

//}

inline int Ponto2D :: getid() const{
    return this-> id;
}

inline void Ponto2D :: setX(double x_){
    this-> x = x;
}