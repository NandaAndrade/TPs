// tempo.cpp
#include "tempo.h"
#include <iostream>

using namespace std;

// contrutor parametrico 1 -> cria um tempo com dias, horas, min e seg definidos.
Tempo::Tempo(int dias, int horas, int min, int seg)
{
    _dias = 0;
    _horas = 0;
    _min = 0;
    _seg = 0;

    _dias = dias;
    _horas = horas;
    _min = min;
    _seg = seg;

    this->checkConsistence(_dias, _horas, _min, _seg);
}

// getters
int Tempo::getDias()
{
    return _dias;
}

int Tempo::getHoras()
{
    return _horas;
}

int Tempo::getMin()
{
    return _min;
}

int Tempo::getSeg()
{
    return _seg;
}

// Checa a consistencia do tempo e altera caso esteja errado.
void Tempo::checkConsistence(int dias, int horas, int min, int seg)
{
    int horasAcum = horas;
    int minAcum = min;

    if (seg > 59)
    {
        _seg = seg % 60;
        minAcum += (seg / 60);
    }

    if (minAcum > 59)
    {
        _min = minAcum % 60;
        horasAcum += (minAcum / 60);
    }
    else
    {
        _min = minAcum;
    }

    if (horasAcum > 23)
    {
        _horas = horasAcum % 24;
        _dias += (horasAcum / 24);
    }
    else
    {
        _horas = horasAcum;
    }
}

// Soma um tempo com outro tempo, serve para atualizar.
Tempo Tempo::sumTempo(Tempo t)
{
    int totalDias = t.getDias() + _dias;
    int totalHoras = t.getHoras() + _horas;
    int totalMin = t.getMin() + _min;
    int totalSeg = t.getSeg() + _seg;

    return Tempo(totalDias, totalHoras, totalMin, totalSeg);
}

// Imprimir o tempo
void Tempo::print()
{
    cout << "Time:" << endl;
    cout << "Total Dias: " << _dias << endl;
    cout << "Total Horas: " << _horas << endl;
    cout << "Total Min: " << _min << endl;
    cout << "Total Seg: " << _seg << endl;
}

// Inicializa o construtor pedindo o usuário as entradas
Tempo Tempo::enterData()
{
    int dias = 0;
    int horas = 0;
    int min = 0;
    int seg = 0;

    cout << "Enter total dias:" << endl;
    cin >> dias;

    cout << "Enter total horas:" << endl;
    cin >> horas;

    cout << "Enter total min:" << endl;
    cin >> min;

    cout << "Enter total seg:" << endl;
    cin >> seg;

    return Tempo(dias, horas, min, seg);
}

void Tempo::addSeg(int seg)
{

    _seg += seg;

    this->checkConsistence(_dias, _horas, _min, _seg);
}

void Tempo::decSeg(int seg)
{

    if (_seg >= seg)
        _seg -= seg;

    this->checkConsistence(_dias, _horas, _min, _seg);
}
