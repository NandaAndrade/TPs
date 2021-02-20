#include <iostream>
#include "Ponto2D.h"

using namespace std;
int main() {

    Ponto2D a(3,5), b(4,8), c;
    c = a + b;
    cout << "a: " << a.getX() << ", " << a.getY()<< std::endl;
    cout << "b: " << b.getX() << ", " << b.getY()<< std::endl;
    cout << "c: " << c.getX() << ", " << c.getY()<< std::endl;
    --a;
    --b;
    cout << "a: " << a.getX() << ", " << a.getY()<< std::endl;
    cout << "b: " << b.getX() << ", " << b.getY()<< std::endl;


    return 0;
}
