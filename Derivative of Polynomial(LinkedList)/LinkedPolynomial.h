#ifndef LP_
#define LP_
#include "PolynomialInterface.h"
#include "Node.h"
#include<tuple>
#include<utility>
using namespace std;
typedef tuple<double,unsigned> Term;
//typedef pair<double,unsigned> Item;

class LinkedPolynomial: public PolynomialInterface
{
  private:
       Node<Term>* headPtr; // Pointer to first node
       int itemCount;  
  public:
    LinkedPolynomial();
    bool isZero() const;
    unsigned getDegree() const;
    bool addTerm( double coefficient , unsigned exponent );
    void clear();
    double evaluate( double x ) const;
    double evalDerivative( double x ) const;
    void print() const;
};
#include "LinkedPolynomial.cpp"
#endif