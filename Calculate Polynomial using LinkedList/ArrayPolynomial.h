/** ADT Polynomial
    Developed by Ben Juliano @ Chico State
    @file PolynomialInterface.h */

#ifndef POLYNOMIAL_
#define POLYNOMIAL_

#include "PolynomialInterface.h"


class ArrayPolynomial: public PolynomialInterface
{
    private:
      int myPoly[30];
      //unsigned maxSize = 31;
    public:
        ArrayPolynomial();
        bool isZero() const;
        unsigned getDegree() const;
        bool addTerm( double coeff , unsigned exp);
        void clear();
        double evaluate( double x ) const;
        void print() const;

};
#include "ArrayPolynomial.cpp"
#endif
