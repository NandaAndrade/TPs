#include <iostream>
#include "Ponto2D.h"

int main()
{
    Ponto2D p1(2, 3);
    Ponto2D p2(3, 5);
    /*std::cout << p2.getX() << p2.getY() << std::endl;
    p2.print();
    p2.setX(7);
    p2.setY(8);
    p2.print();
    double res = p2.distToOrig();
    double res2 = p2.distTo(p1);
    std::cout << res << "-----" << res2 << std::endl;
    int i = p1.getId();
    std::cout << i << std::endl;
    p1.sumOf(p2);
    p1.print();
    Ponto2D p3 = p1.sumPoint(p2);
    p3.print();*/
    Ponto2D p3 (p1);
    p3.print();
    Ponto2D p4 = p2;
    p4.print();
    return 0;
}