// matrix.h (header file)
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

class Matrix
{
private:
    double **m; // m é um array 2D a ser implementado como um pointer de pointers
    int nRows;  // numero de linhas
    int nCols;  //  numero de colunas

public:
    // Construtores
    //Matrix();
    Matrix(int rows = 1, int cols = 1, const double &elem = 0.0);
    Matrix(ifstream &myFile);
    Matrix(const Matrix &that);

    // destrutor
    ~Matrix();

    // basic getters
    int getRows() const;
    int getCols() const;
    double get(int row, int col) const;

    // other methods
    Matrix transpose();
    void print() const;
    void unit(); // colocar codigo de erro para matriz não quadrada
    void zeros();
    void ones();

    // sobrecarga de operadores
    Matrix operator+(const Matrix &that);
    Matrix operator-(const Matrix &that);
    Matrix &operator*(const Matrix &that); //testa
    Matrix &operator+=(const Matrix &that);
    Matrix &operator-=(const Matrix &that);
    void operator*=(const int n);
    Matrix &operator*=(const Matrix &that);
    Matrix &operator~(); //retorna a referência a uma matrix criada transposta do argumento
    double &operator()(int i, int j);
    bool operator==(const Matrix &that);
    bool operator!=(const Matrix &that);
    ostream &operator<<(ostream &out, const Matrix &that);
    istream &operator>>(istream &in, const Matrix &that);
};