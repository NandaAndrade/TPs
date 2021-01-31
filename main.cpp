// main.cpp
#include <iostream>
#include "Tempo.h"

using namespace std;

int main(){

    // Recebe os dados e inicializa no construtor.
    Tempo t = Tempo::enterData();    

    cout << endl;

    // Print the Tempo
    t.print();

    cout << endl;
    
    t.addSeg(150);

    cout << "Tempo depois de add segundos:" << endl;

    t.print();

    cout << endl;
    
    t.decSeg(70);

    cout << "Tempo depois de tirar segundos:" << endl;

    t.print();
    return 0;
}