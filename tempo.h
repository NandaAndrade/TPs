// tempo.h

#include <iostream>
class Tempo {
    private:
        int _dias;
        int _horas;
        int _min;
        int _seg;
    
    public:
        // Construtores
        Tempo(int dias, int horas, int min, int seg);
        // Destrutor Por ser um caso simples, optamos por deixar o destrutor criado pelo compilador.
        // ~Tempo();

        // getters
        int getDias();
        int getHoras();
        int getMin();
        int getSeg();

        // metodos
        void checkConsistence(int dias, int horas, int min, int seg);
        Tempo sumTempo(Tempo);
        void print();
        static Tempo enterData();
        void addSeg(int);
        void decSeg(int);        
};