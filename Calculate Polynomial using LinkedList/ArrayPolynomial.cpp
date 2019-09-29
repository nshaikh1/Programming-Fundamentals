#include "ArrayPolynomial.h"
#include<iostream>
#include<cmath>
using namespace std;
ArrayPolynomial::ArrayPolynomial()
{
    for(unsigned i = 0 ; i < 31 ; i ++ )
    {
        myPoly[i] = 0;
    }
}
bool ArrayPolynomial::isZero() const
{
    int size = 0;
    for(int i = 0;i<31&&myPoly[i]!=0;i++)
    {
        size = size + 1;
    }
    if (size>0)
        return true;
    else
        return false;
}
bool ArrayPolynomial::addTerm( double coeff , unsigned exp)
{
//exp = index of array
//coeff = value at index
    if(exp > 30)
        return false;
    else
        {
            myPoly[exp] = coeff;
            return true;
        }
}

unsigned ArrayPolynomial::getDegree() const
{
    int size = 0;
    for(unsigned i = 0;i<31;i++)
    {
        size = size + 1;
    }
    return size;
}
void ArrayPolynomial:: print() const
{
    for(unsigned i = 0 ;i<31&&myPoly[i]!=0;i++)
    {
        cout<<myPoly[i];
    }
}

double ArrayPolynomial:: evaluate( double x ) const
{
//x = value
    double final_val = 0.0;
    for(unsigned i = 1 ; i < 31; i++)//skip first term as its a constant always or 0
    {
        final_val = final_val + ( myPoly[i]*(pow(x,i)));
    }
    final_val = final_val + myPoly[0]; // add or sub the constant
    return final_val;
}

void ArrayPolynomial:: clear()
{
  for(unsigned i = 0 ; i < 31 ; i ++)
  {
    myPoly[i] = 0;
  }
}


