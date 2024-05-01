#include <iostream>
#include "vector.h"
#include "matrix.h"

using namespace chavira;

int main()
{
    // test 1: default values for vector
    std::cout << "test 1: default values for vector\n";
    vector v1;
    v1.print();

    // test 2: vector transpose
    vector v2(7,9);  // default is column vector
    std::cout << "------------------------------------------------\n";
    std::cout << "test 2: vector transpose\n";
    v2.transpose().print();

    // test 3: vector1,vector2;vector2,vector1 +,-,*
    std::cout << "------------------------------------------------\n";
    std::cout << "test 3: vector1,vector2;vector2,vector1 +,-,*\n";
    vector v3(3,2);
    (v2.transpose() + v3.transpose()).print();
    (v3.transpose() + v2.transpose()).print();
    (v2.transpose() - v3.transpose()).print();
    (v3.transpose() - v2.transpose()).print();
    (v2.transpose() * v3.transpose()).print();
    (v3.transpose() * v2.transpose()).print();

    // test 4: vector,scalar;scalar,vector +,-,*
    std::cout << "------------------------------------------------\n";
    std::cout << "test 4: vector,scalar;scalar,vector +,-,*\n";
    (v2.transpose() + 12.3).print();
    (12.3 + v2.transpose()).print();
    (v2.transpose() - 12.3).print();
    (12.3 - v2.transpose()).print();
    (v2.transpose() * 12.3).print();
    (12.3 * v2.transpose()).print();

    // test 5: constructor (i) for matrix
    std::cout << "------------------------------------------------\n";
    std::cout << "test 5: constructor (i) for matrix\n";
    matrix m1;
    m1.print();

    // test 6: constructor (ii) for matrix
    std::cout << "------------------------------------------------\n";
    std::cout << "test 6: constructor (ii) for matrix\n";
    matrix m2(v2,v3);
    m2.print();
    matrix m3(v2.transpose(),v3.transpose());
    m3.print();

    // test 7: constructor (iii) for matrix
    std::cout << "------------------------------------------------\n";
    std::cout << "test 7: constructor (iii) for matrix\n";
    matrix m4(1,2,3,4);
    m4.print();

    // test 8: check matrix transpose
    std::cout << "------------------------------------------------\n";
    std::cout << "test 8: check matrix transpose\n";
    m4.transpose().print();

    // test 9: check identity matrix
    std::cout << "------------------------------------------------\n";
    std::cout << "test 9: check identity matrix\n";
    std::cout << "m1.is_identity() = " << m1.is_identity() << std::endl;
    std::cout << "m2.is_identity() = " << m2.is_identity() << std::endl;
    std::cout << "m3.is_identity() = " << m3.is_identity() << std::endl;
    std::cout << "m4.is_identity() = " << m4.is_identity() << std::endl;

    // test 10: calculate determinant
    std::cout << "------------------------------------------------\n";
    std::cout << "test 10: calculate determinant\n";
    std::cout << "m1.determinant() = " << m1.determinant() << std::endl;
    std::cout << "m2.determinant() = " << m2.determinant() << std::endl;
    std::cout << "m3.determinant() = " << m3.determinant() << std::endl;
    std::cout << "m4.determinant() = " << m4.determinant() << std::endl;

    // test 11: calculate inverse
    std::cout << "------------------------------------------------\n";
    std::cout << "test 11: calculate inverse\n";
    m2.inverse().print();
    m3.inverse().print();
    m4.inverse().print();

    // test 12: calculate matrix1,matrix2 dot product
    std::cout << "------------------------------------------------\n";
    std::cout << "test 12: calculate matrix1,matrix2 dot product\n";
    dot(m1,m2).print();
    dot(m2,m1).print();
    dot(m2,m3).print();
    dot(m3,m2).print();
    dot(m4,m4).print();
    dot(m4,m4.inverse()).print();

    // test 13: calculate matrix,vector dot product
    std::cout << "------------------------------------------------\n";
    std::cout << "test 13: calculate matrix,vector dot product\n";
    vector v4(5,6);
    dot(m4.inverse(),v4).print();

    // test 14: matrix1,matrix2;matrix2,matrix1 +,-,*
    std::cout << "------------------------------------------------\n";
    std::cout << "test 14: matrix1,matrix2;matrix2,matrix1 +,-,*\n";
    (m2 + m3).print();
    (m3 + m2).print();
    (m2 - m3).print();
    (m3 - m2).print();
    (m2 * m3).print();
    (m3 * m2).print();

    // test 15: matrix,scalar;sclar,matrix +,-,*
    std::cout << "------------------------------------------------\n";
    std::cout << "test 15: matrix,scalar;sclar,matrix +,-,*\n";
    (m2 + 5).print();
    (5 + m2).print();
    (m2 - 6).print();
    (6 - m2).print();
    (m2 * 7).print();
    (7 * m2).print();

    return 0;
}