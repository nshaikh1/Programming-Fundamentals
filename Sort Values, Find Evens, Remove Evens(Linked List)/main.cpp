#include<iostream>
//#include "Node.h"
using namespace std;

struct Node{
  unsigned data;
  Node* next;
};

void insert(Node* &headptr, const unsigned input)
{
  

  Node* node = new Node;
  node->next = nullptr;
  if (headptr == nullptr) {
    node->next = nullptr;
    node->data = input;
    headptr = node;
    return;
  } else {
    Node* temp = headptr;
    if (temp->data >= input) {
      node->next = headptr;
      node->data = input;
      headptr = node;
      return;
    }
    Node* temp_pre = temp;
    temp = headptr->next;
    while (temp != nullptr && temp->data < input) {
      temp_pre = temp;
      temp = temp->next;
      node->data = input;
    }
    if (temp == nullptr) {
      temp_pre->next = node;
      node->next = nullptr;
      node->data = input;
    }
    temp_pre->next = node;
    node->next = temp;
    node->data = input;
  }
}
void display(Node* headptr)
{
  while(headptr)
  {
    cout<<" "<<headptr->data;
    headptr = headptr->next;
  }
}
int getSize(Node* headptr)
{
  int mysize = 0;
  while(headptr)
  {
    mysize = mysize + 1;
    headptr = headptr->next;
  }
  return mysize;
}
int getEvens(Node* headptr)
{
  int evenCount = 0;
  while(headptr)
  {
    if(headptr->data%2 == 0)
      evenCount = evenCount + 1;
    headptr = headptr->next;
  }
  return evenCount;
}

void removeEvens(Node* &headptr)
{
  while((headptr==0||headptr->data%2==0 ) && headptr!=nullptr)//to remove initial evens, and move headptr to correct position
  {
    headptr = headptr->next;
  }
  Node* curr = headptr;
   Node* prev = headptr;
   while(curr)
   {
     if(curr->data%2 == 0)
     {
       while(prev->next!=curr)
       {
         prev = prev->next;
       }
       prev->next = curr->next;
     }
     curr = curr->next;
   }
   
}
int countWithoutEven(Node* headptr)
{
  int woevens = 0;
  while(headptr)
  {
      woevens = woevens + 1;
    headptr = headptr->next;
  }
  return woevens;
}

 int main()
 {
   unsigned input = 0;
   Node* headptr = nullptr;
   //cout << "=====" << endl;
   while(cin>>input)
   {
     //cout << input << endl;
    insert(headptr,input);
   }

  cout<<"Sorted list ("<<getSize(headptr)<<" elements):"<<endl;
  display(headptr);
  cout<<endl;
  cout<<"Found "<<getEvens(headptr)<<" even numbers"<<endl;
    removeEvens(headptr);
  cout<<"List with even numbers removed ("<<countWithoutEven(headptr)<<" elements):"<<endl;
  display(headptr);
  cout<<endl;
 }
