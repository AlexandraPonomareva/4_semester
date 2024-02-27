#include <iostream>

class Matrix {
private:
    int** data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int rows, unsigned int columns);
    ~Matrix();

    int* operator[](unsigned int index);
    void fillRandom();

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    Matrix& operator+=(const Matrix& matrix);
    Matrix operator+(const Matrix& matrix) const;
    Matrix& operator-=(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;

    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;
};