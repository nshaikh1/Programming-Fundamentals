#include<iostream>
#include "Node.h"

using namespace std;

template< class T >
void insert( Node<T>* &headPtr , const T& entry )
{
	// Create a new node and have the next pointer point to current front
	Node<T> *newNodePtr = new Node<T>( entry , headPtr );
	// Current front now becomes this new node
	headPtr = newNodePtr;
}
template< class T >
void display( Node<T> *headPtr )
{
	Node<T> *currNodePtr = headPtr;
	while( currNodePtr ) // as long as not nullptr
	{
		cout << currNodePtr->getItem() << " ";
		currNodePtr = currNodePtr->getNext();
	}
}
template<class T>
T getMax(Node<T>* ptr)
{
  T max = 0;
  if(max == 0)
    max = ptr->getItem();
  else if(max<ptr->getItem())
    max = ptr->getItem();
  return max;
}
template<class T>
T getSum(Node<T>* ptr)
{
  T sum = 0;
  while(ptr)
  {
    sum=sum+ptr->getItem();
    ptr = ptr->getNext();
  }
  return sum;
}
template<class T>
void getRev(Node<T>* ptr)
{   
  if(ptr==NULL)
    return;
  getRev(ptr->getNext());
  cout<<  ptr->getItem() << " ";
}
int main()
{
 int input = 0;
 Node<int>* ptr = nullptr;
 while(cin>>input)
 {
   		insert<int>( ptr , input);
 }
 //cout<<"Contents: "<<getRev(ptr)<<endl;
 if(ptr){
 cout<<"Contents: ";
 getRev(ptr);
 cout<<endl;
 
 cout<<"Sum: " << getSum(ptr) << endl;
 cout<<"Maximum: " << getMax(ptr) << endl;
 }else{cout<<"Contents: <EMPTY>"<<endl;}

}