#include <iostream>
#include "Ponto2D.h"

int main() {
    Ponto2D p1(2,3);
    Ponto2D p2(3, 5);
    std::cout << p2.getX() << p2.getY() << std::endl;
    p2.print();
    p2.setX(7);
    p2.setY(8);
    p2.print();
    double res = p2.distToOrig();
    double res2 = p2.distTo(p1);
    std::cout << res << "-----" << res2 << std::endl;
    return 0;
}