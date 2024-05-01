#include "vector.h"
#include "matrix.h"

#include <iostream>
#include <cstdlib>
#include <cassert>

namespace chavira{

    matrix::matrix(double a11, double a12, double a21, double a22){
      A11 = a11;
      A12 = a12; 
      A21 = a21;
      A22 = a22;
     }

    matrix::matrix(vector v1, vector v2) {
        if (v1.getisrow()) {
          A11 = v1.getx1();  A12 = v1.getx2();
          A21 = v2.getx1(); A22 = v2.getx2();
    } else {
         A11 = v1.getx1(); A12 = v2.getx1();
         A21 = v1.getx2(); A22 = v2.getx2();
      }
    }
        

    matrix matrix::transpose() {
        return matrix(A11, A21, A12, A22);
    }

    bool matrix::is_identity() {
        return (A11 == 1.0 && A12 == 0.0 && A21 == 0.0 && A22 == 1.0);
    }

    double matrix::determinant() {
        return ((A11 * A22) - (A12 * A21));
    }

    matrix matrix::inverse() {
        assert(determinant() != 0);
        double inverseD = 1.0 / determinant();
        return matrix(A22 * inverseD, -A12 * inverseD, -A21 * inverseD, A11 * inverseD);
    }

    void matrix::print() {
        std::cout << "[" << A11 << " " << A12 << std::endl;
        std::cout << " " << A21 << " " << A22 << "]" << std::endl;
    }

    double matrix::geta11() {
        return A11;
    }

    double matrix::geta12() {
        return A12;
    }

    double matrix::geta21() {
        return A21;
    }

    double matrix::geta22() {
        return A22;
    }

    matrix dot(matrix A1, matrix C2) {
        double a11 = A1.geta11() * C2.geta11() + A1.geta12() * C2.geta21();
        double a12 = A1.geta11() * C2.geta12() + A1.geta12() * C2.geta22();
        double a21 = A1.geta21() * C2.geta11() + A1.geta22() * C2.geta21();
        double a22 = A1.geta21() * C2.geta12() + A1.geta22() * C2.geta22();
        return matrix(a11, a12, a21, a22);
    }

    vector dot(matrix A,vector x) {
        double x1 = A.geta11() * x.getx1() + A.geta12() * x.getx2();
        double x2 = A.geta21() * x.getx1() + A.geta22() * x.getx2();
        return vector(x1, x2, x.getisrow());
    }

    matrix operator+(matrix m1, matrix m2) {
        return matrix(m1.geta11() + m2.geta11(), m1.geta12() + m2.geta12(), m1.geta21() + m2.geta21(), m1.geta22() + m2.geta22());
    }

    matrix operator+(matrix m, double scalar) {
        return matrix(m.geta11() + scalar, m.geta12() + scalar, m.geta21() + scalar, m.geta22() + scalar);
    }

     matrix operator+(double scalar, matrix m) {
        return matrix(scalar + m.geta11(), scalar + m.geta12(), scalar + m.geta21(), scalar + m.geta22());
    }

    matrix operator-(matrix m2, matrix m1) {
        return matrix(m2.geta11() - m1.geta11(), m2.geta12() - m1.geta12(), m2.geta21() - m1.geta21(), m2.geta22() - m1.geta22());
    }

    matrix operator-(matrix m, double scalar) {
        return matrix(m.geta11() - scalar, m.geta12() - scalar, m.geta21() - scalar, m.geta22() - scalar);
    }

    matrix operator-(double scalar, matrix m) {
        return matrix(scalar - m.geta11(), scalar - m.geta12(), scalar - m.geta21(), scalar - m.geta22());
    }

    matrix operator*(matrix m1, matrix m2) {
        // Element-wise multiplication
        return matrix(m1.geta11() * m2.geta11(), m1.geta12() * m2.geta12(), m1.geta21() * m2.geta21(), m1.geta22() * m2.geta22());
    }

    matrix operator*(matrix m, double scalar) {
        return matrix(m.geta11() * scalar, m.geta12() * scalar, m.geta21() * scalar, m.geta22() * scalar);
    }

     matrix operator*(double scalar, matrix m) {
        return matrix(scalar * m.geta11(), scalar * m.geta12(),scalar * m.geta21(), scalar * m.geta22());
    }
}