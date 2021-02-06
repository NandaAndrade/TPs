//Ponto2D_H
#include <iostream>

class Ponto2D
{
public:
    //os contrutores tem que buscar id disponivel e incrementar
    Ponto2D();
    Ponto2D(float x, float y);

    //o destrutor tem que decrementar id disponivel
    ~Ponto2D();

private:
    float _x;
    float _y;
    int _id;
}