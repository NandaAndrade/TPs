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
    Matrix diferent(const Matrix &that);

    // sobrecarga de operadores
    Matrix operator+(const Matrix &that); //certo
    Matrix operator-(const Matrix &that); //certo
    Matrix &operator*(const Matrix &that); 
    Matrix &operator+=(const Matrix &that); //certo
    Matrix &operator-=(const Matrix &that); //certo
    void operator*=(const int n); //certo
    Matrix &operator*=(const Matrix &that); //certo
    Matrix &operator~();
    double &operator()(int i, int j); //certo
    bool operator==(const Matrix &that); //certo
    bool operator!=(const Matrix &that); //certo
    //ostream &operator<<(const Matrix &that);
    //istream &operator>>(const Matrix &that);
};