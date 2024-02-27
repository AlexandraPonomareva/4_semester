#include "laba2.h"
#include <iostream>

int main() {
    Matrix m1(2,  2);
    m1.fillRandom();
    std::cout << "Matrix  1:\n" << m1 << std::endl;

    Matrix m2(2,  2);
    m2.fillRandom();
    std::cout << "Matrix  2:\n" << m2 << std::endl;

    Matrix m3 = m1 + m2;
    std::cout << "Matrix  1 + Matrix  2:\n" << m3 << std::endl;

    Matrix m4 = m1 - m2;
    std::cout << "Matrix  1 - Matrix  2:\n" << m4 << std::endl;

    Matrix m5 = m1 * m2;
    std::cout << "Matrix  1 * Matrix  2:\n" << m5 << std::endl;

    return  0;
}
