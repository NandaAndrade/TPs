//Ponto2D_H
#include <iostream>

class Ponto2D
{
public:
    //os contrutores tem que buscar id disponivel e incrementar
    Ponto2D();
    Ponto2D(float x, float y);

    // Função membro para escrever (imprimir) as coordenadas do ponto na tela
    void print();

    // Função membro para calcular a distância do ponto a origem do sistema de coordenadas cartesiano
    double distToOrig() const;

    // Função membro para calcular a distância entre dois pontos p1 e p2, onde p1 é o objeto que chama a função
    double distTo(Ponto2D p) const;

    // Função membro que modifica as coordenadas do objeto corrente p1 somando às
    // suas coordenadas um novo ponto p2, que deve ser passado por argumento.
    void sumOf(Ponto2D p);

    // Função membro que retorna um ponto p3 que é o resultado da soma entre dois pontos p1 e p2,
    // onde p1 é o objeto que chama a função.
    Ponto2D sumOf(Ponto2D p) override;

    //o destrutor tem que decrementar id disponivel
    ~Ponto2D();

private:
    float _x;
    float _y;
    int _id;
};