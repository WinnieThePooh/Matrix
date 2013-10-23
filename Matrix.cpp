/* 
 * File:   Matrix.cpp
 * Author: snickers
 * 
 * Created on 22 Октябрь 2013 г., 16:03
 */

#include "Matrix.h"

Matrix::Matrix(int x, int y) {
    rows = x;
    columns = y;

    matr = new float *[x];
    for (int i = 0; i < x; i++) {
        matr[i] = new float [y];
    }

}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete [] matr[i];
    }
    delete [] matr;
}

int Matrix::getRows() {
    return rows;
}

int Matrix::getColumns() {
    return columns;
}

float Matrix::getValue(int x, int y) {
    return matr[x][y];
}

void Matrix::setValue(int x, int y, float value) {
    matr[x][y] = value;
}

float** Matrix::getArray() {
    return matr;
}

//-------------------------------------------
//Оператор сложение матриц

Matrix *Matrix::operator+(Matrix &matr2) {
    if ((rows == matr2.getRows()) and (columns == matr2.getColumns())) {
        Matrix *newMatr = new Matrix(rows, columns);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++) {
                float value = matr[i][j] + matr2.getValue(i, j);
                newMatr-> setValue(i, j, value);
            }
        return newMatr;
    }
    //кидаем исключение :-)
    throw ("Matrices  have different sizes");
}

//-------------------------------------------
//Оператор умножения матриц

Matrix* Matrix::operator*(Matrix &matr2) {
    if (rows == matr2.getColumns()) {
        Matrix *newMatr = new Matrix(rows, columns);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++) {
                newMatr->setValue(i, j, sum(this, &matr2, i, j));
            }
        
        return newMatr;
    }
    //кидаем исключение :-)
    throw ("M1 Rows dont  not = M2 columns");
}

//-------------------------------------------
//Нахождение суммы для вычисления элемента

float Matrix::sum(Matrix * matr1, Matrix * matr2, int i, int j) {
    int rows = matr1->getRows();
    float Sum = 0;

    for (int n = 0; n < rows; n++) {
        Sum += matr1->getValue(i, n) * matr2->getValue(n, j);
    }

    return Sum;
}