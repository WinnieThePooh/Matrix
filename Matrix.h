/* 
 * File:   Matrix.h
 * Author: snickers
 *
 * Created on 22 Октябрь 2013 г., 16:03
 */

#ifndef MATRIX_H
#define	MATRIX_H
#include <stdexcept>

class Matrix {
public:
    Matrix(int, int);

    virtual ~Matrix();

    int getRows();
    int getColumns();
    float** getArray();
    float getValue(int x, int y);
    void setValue(int x, int y, float value);

    float operator()(int x, int y) {
        return matr[x][y];
    }

    void operator()(int x, int y, float val) {
        matr[x][y] = val;
    }

    Matrix* operator+(Matrix &matr2);
    Matrix* operator*(Matrix &matr2);


private:
    int rows, columns;
    float **matr;// хз почему ** , а не * :(
    
    float sum(Matrix * matr1, Matrix * matr2, int i, int j);
};

#endif	/* MATRIX_H */

