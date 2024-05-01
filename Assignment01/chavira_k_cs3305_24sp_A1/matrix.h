#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"
#include <iostream>
#include <cstdlib>


namespace chavira {
    class matrix{
        public:
           matrix(double a11 = 1 , double a12 = 0 , double a21 = 0, double a22 = 1);
           matrix(vector v1, vector v2);
           matrix transpose();
           bool is_identity();
           double determinant();
           matrix inverse();
           void print();

            double geta11();
            double geta12();
            double geta21();
            double geta22();


        private:
           double A11;
           double A12;
           double A21;
           double A22;

    };

    matrix dot(matrix A1, matrix C2);
    vector dot(matrix A, vector x);

    matrix operator+(matrix m1, matrix m2);
    matrix operator+(matrix m,  double scalar);
    matrix operator+(double scalar, matrix m);
    matrix operator-(matrix m1, matrix m2);
    matrix operator-(matrix m,  double scalar);
    matrix operator-(double scalar, matrix m);
    matrix operator*(matrix m1, matrix m2);
    matrix operator*(matrix m, double scalar);
    matrix operator*(double scalar, matrix m);

}

#endif