#include "laba2.h"
#include <cstdlib>

Matrix::Matrix(unsigned int rows, unsigned int columns) {
    m = rows;
    n = columns;

    data = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; i++) {
        delete[] data[i];
    }

    delete[] data;
}

int* Matrix::operator[](unsigned int index) {
    return data[index];
}

void Matrix::fillRandom() {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] = rand() % 10;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix& Matrix::operator+=(const Matrix& matrix) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] += matrix.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& matrix) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] + matrix.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator-=(const Matrix& matrix) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] -= matrix.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& matrix) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& matrix) const {
    Matrix result(m, matrix.n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix& matrix) const {
    if (m != matrix.m || n != matrix.n) {
        return false;
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (data[i][j] != matrix.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& matrix) const {
    return !(*this == matrix);
}