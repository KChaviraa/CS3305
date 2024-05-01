#include "vector.h"
#include <iostream>

namespace chavira {

vector::vector(double x1, double x2, bool isrow){
    x01 = x1;
    x02 = x2;
    is_row = isrow;
}

    vector vector::transpose() {
        return vector(x01, x02, !is_row);
    }

    void vector::print()  {
        std::cout << "[";
        if (is_row) {
            std::cout << x01 << " " << x02;
        } else {
            std::cout << x01 << std::endl << x02;
        }
        std::cout << "]" << std::endl;
    }

    double vector::getx1(){
        return x01;
    }

    double vector::getx2() {
        return x02;
    }

    bool vector::getisrow(){
        return is_row;
    }

    vector operator+(vector v1, vector v2) {
        return vector(v1.getx1() + v2.getx1(), v1.getx2() + v2.getx2(), v1.getisrow());
    }

    vector operator+(vector v, double scalar) {
        return vector(v.getx1() + scalar, v.getx2() + scalar, v.getisrow());
    }

    vector operator+(double scalar, vector v){
          return vector(scalar + v.getx1(), scalar + v.getx2(), v.getisrow());
     }

    vector operator-(vector v1, vector v2) {
        return vector(v1.getx1() - v2.getx1(), v1.getx2() - v2.getx2(), v1.getisrow());
    }

    vector operator-(vector v, double scalar) {
        return vector(v.getx1() - scalar, v.getx2() - scalar, v.getisrow());
    }

    vector operator-(double scalar, vector v) {
        return vector(scalar - v.getx1(), scalar - v.getx2(), v.getisrow());
    }

    vector operator*(vector v1, vector v2) {
        return vector(v1.getx1() * v2.getx1(), v1.getx2() * v2.getx2(), v1.getisrow());
    }

    vector operator*( vector v, double scalar) {
        return vector(v.getx1() * scalar, v.getx2() * scalar, v.getisrow());
    }

     vector operator*(double scalar, vector v){
          return vector(scalar * v.getx1(), scalar * v.getx2(), v.getisrow());
     }
}