/* 
 * File:   main.cpp
 * Author: snickers
 *
 * Created on 22 Октябрь 2013 г., 15:55
 */

#include <cstdlib>
#include <iostream>
#include "Matrix.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int x =3, y = 3;
    Matrix matr1(x, y); //матрица 10х10
    Matrix matr2(x, y); //матрица 10х10

    for (int i = 0; i < x; i++) {
        for (int j = 0; j <y; j++) {
            float val = j;
            matr1(i, j, val);
            matr2(x-1-i,y-1- j, val);
        }
    }
cout << endl;
    Matrix* matr3 = matr1 * matr2;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << matr1(i, j)<< " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << matr2.getValue(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << matr3->getValue(i, j)<< " ";
        }
        cout << endl ;
    }
    
    
  float **arr =  matr3->getArray();
  cout << arr[1][1];
    
    delete matr3;

    return 0;
}

