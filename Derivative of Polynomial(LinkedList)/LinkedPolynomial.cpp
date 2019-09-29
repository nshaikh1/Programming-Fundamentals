#include<iostream>
#include "LinkedPolynomial.h"
#include<tuple>
#include<utility>
#include<iomanip>
#include<cmath>
using namespace std;


LinkedPolynomial::LinkedPolynomial()
{
  headPtr = nullptr;
  itemCount = 0;
}
void LinkedPolynomial::clear()
{
  headPtr = nullptr;
  itemCount = 0;
}

void LinkedPolynomial::print() const
{
  Node<Term>* temp = headPtr;
  //cout<<"Now:"<<headPtr<<endl;
  while(temp)
  {
  cout<<get<0>(temp->getItem())<<endl;//coeff
  cout<<get<1>(temp->getItem())<<endl;//degree
  temp = temp->getNext();
  }
  //cout<<get<0>(headPtr->getItem());
}

bool LinkedPolynomial::addTerm( double coefficient , unsigned exponent )
{
  tuple<double,unsigned> myPair;
  myPair = make_tuple(coefficient,exponent);
  Node<Term>* newNode = new Node<Term>(myPair,headPtr);//--->ERROR
  headPtr = newNode;
  itemCount++;
  return true;
}

bool LinkedPolynomial::isZero() const
{
  if(headPtr==nullptr)
    return true;
  else
    return false;
}
unsigned LinkedPolynomial::getDegree() const
{
  unsigned deg = 0;
  deg = itemCount - 1;
  return deg;
}
double LinkedPolynomial::evaluate( double x ) const
{
    double local_coeff = 0.0;
    unsigned local_degree = 0;
    double eval = 0.0;
    Node<Term>* temp = headPtr;
    while(temp)
    {
      local_coeff = get<0>(temp->getItem());
      local_degree = get<1>(temp->getItem());
      eval = eval + (local_coeff*pow(x,local_degree));
      temp = temp->getNext();
    }
    return eval;
}
double LinkedPolynomial::evalDerivative( double x ) const
{
  double local_coeff = 0.0;
  double myVal = 0.0;
  unsigned local_degree = 0;
  double first_term = 0;
  Node<Term>* temp = headPtr;
  while(temp)
  {
    local_coeff = get<0>(temp->getItem());
    local_degree = get<1>(temp->getItem());
    //
    if(local_degree!=0){
    //cout<<"Coeff:"<<local_coeff<<endl;
    //cout<<"Degree:"<<local_degree<<endl;
    first_term = local_coeff * local_degree;
    //cout<<"Term1:"<<first_term<<endl;
    local_degree = local_degree - 1;
    //cout<<"New Degree:"<<local_degree<<endl;
    myVal = myVal + (first_term)*(pow(x,local_degree));
    //
    }
    temp = temp->getNext();
  }
  return myVal;
}
