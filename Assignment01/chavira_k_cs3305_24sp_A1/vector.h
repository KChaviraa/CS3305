#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>

namespace chavira {
    class vector {
        public:
            vector(double x1=1.0 , double x2=1.0, bool isrow = false);
            vector transpose();
            void print();

            double getx1();
            double getx2();
            bool getisrow();


        private:
            double x01;
            double x02;
            bool is_row;
    };


    vector operator+(vector v1, vector v2);
    vector operator+(vector v,  double scalar);
    vector operator+(double scalar, vector v);
    vector operator-(vector v1, vector v2);
    vector operator-(vector v, double scalar);
    vector operator-(double scalar, vector v);
    vector operator*(vector v1, vector v2 );
    vector operator*(vector v, double scalar);
    vector operator*(double scalar, vector v);
}

#endif