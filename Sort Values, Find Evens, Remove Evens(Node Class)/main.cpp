#include<iostream>
#include "Node.h"

using namespace std;
template<class T>
void insert(T input,Node<T>* &headPtr )
{
  if(headPtr==nullptr)
  {
    Node<T>* myNext = nullptr;
    Node<T>* myPrev = nullptr;
    Node<T>* newNode = new Node<T>(input,myNext,myPrev);
    headPtr = newNode;
  }else
  {
    if(headPtr->getItem()>=input)
    {
      Node<T>* myNext = headPtr;
      Node<T>* myPrev = nullptr;
      Node<T>* newNode = new Node<T>(input,myNext,myPrev);
      headPtr->setPrev(newNode);
      headPtr = newNode;
    }else if(headPtr->getItem()<input)
    {
      Node<T>* myNext = headPtr;
      Node<T>* myPrev = nullptr;
      while(myNext->getItem()<=input && myNext->getNext()!=myPrev)
      {
        myNext = myNext->getNext();
      }
      myPrev = headPtr;
      while(myPrev->getNext()!=myNext && myPrev->getNext()!=nullptr)
      {
        myPrev = myPrev->getNext();
      }
      if(myNext->getNext()==nullptr&&input>=myNext->getItem())
      {
        Node<T>* newNode = new Node<T>(input,nullptr,myNext);
        myNext->setNext(newNode);
      }else
      {

        Node<T>* newNode = new Node<T>(input,myNext,myPrev);
        myPrev->setNext(newNode);
        myNext->setPrev(newNode);
        
      }
      
      
    }
  }
}

template<class T>
void display_list(Node<T>* headPtr)
{
  if(headPtr!=nullptr)
  cout<<" ";
  while(headPtr)
  {
    if(headPtr->getNext()!=nullptr)
    cout<<headPtr->getItem()<<" ";
    else
    cout<<headPtr->getItem();
    headPtr = headPtr->getNext();
  }
}
template<class T>
T getEvenCount(Node<T>* headPtr)
{
  T evens = 0;
  while(headPtr!=nullptr)
  {
    if(headPtr->getItem()%2 == 0)
    evens++;
    headPtr = headPtr->getNext();
  }
  return evens;
}
template<class T>
void removeEvens(Node<T>* &headPtr)
{
  while(headPtr!=nullptr && headPtr->getItem()%2==0)
  {
    headPtr->setPrev(nullptr);
    headPtr = headPtr->getNext();
  }
  Node<T>* myCurr = headPtr;
  Node<T>* myPrev = headPtr;
  while(myCurr)
  {
    if(myCurr->getItem()%2==0)
    {
      myPrev = myCurr->getPrev();
      if(myCurr->getNext()==nullptr)
      {
        myPrev->setNext(nullptr);
      }else
      {
        myPrev->setNext(myCurr->getNext());
        myCurr = myCurr->getNext();
        myCurr->setPrev(myPrev);
        myCurr = myPrev;
      }
    }
    myCurr = myCurr->getNext();
  } 
}
template<class T>
T getSortedCount(Node<T>* headPtr)
{
  T cnt = 0;
  while(headPtr)
  {
    cnt++;
    headPtr = headPtr->getNext();
  }
  return cnt;
}

template<class T>
T getoddcnt(Node<T>* headPtr)
{
  T cnt = 0;
  while(headPtr)
  {
    cnt++;
    headPtr = headPtr->getNext();
  }
  return cnt;
}
/*
Sorted list (10 elements):                                                      
 6 9 12 16 24 27 31 43 50 52                                                    
Found 6 even numbers                                                            
List with even numbers removed (4 elements):                                    
 9 27 31 43                       
*/
int main()
{
  Node<int>* headPtr = nullptr;
  int input = 0;
  while(cin>>input)
  {
    //cout<<input<<endl;
    insert(input,headPtr);
    //display_list(headPtr);
  }
    cout<<"Sorted list ("<<getSortedCount(headPtr)<<" elements):"<<endl;
    display_list(headPtr);
    cout<<endl;
   
    cout<<"Found "<<getEvenCount(headPtr)<<" even numbers"<<endl;
    removeEvens(headPtr);
    cout<<"List with even numbers removed ("<<getSortedCount(headPtr)<<" elements):"<<endl;
    display_list(headPtr);
    cout<<endl;
}
