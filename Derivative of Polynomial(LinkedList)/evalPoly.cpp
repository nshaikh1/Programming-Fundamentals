#include<iostream>
#include "Node.h"
#include "LinkedPolynomial.h"
#include<tuple>
#include<vector>
#include<sstream>


using namespace std;

    vector<string> split( const string& s , char delimiter )
    {
        vector<string> tokens;          
        string token;                   
        istringstream tokenStream(s);   
        while( getline( tokenStream , token , delimiter ) )
            tokens.push_back(token);    
        return tokens;
    }
//turnin test case    
/*-2^M                                                                            
5 0 1 6^M                                                                       
1 -1^M                                                                          
7 6 -1^M                                                                        
-1 1^M                                                                          
7 6 -1^M                                                                        
3 0 0 -4 0 2^M                                                                  
1 2 3 4 5*/

int main()
{
  LinkedPolynomial myPClass;
  //tuple<double,unsigned> myPair;
  //myPair = make_tuple(5.5,7);  cout<<get<1>(myPair)<<endl;*/
  string input;        
  unsigned myPower = 0;    
  char   delimiter = ' ';      
  vector<string> listOfTokens; 
  unsigned line_no = 1; //to represent the line being read from input (1,2)
  while( getline( cin , input ) ) 
  {

    listOfTokens = split( input , delimiter );
    if(line_no == 1)
    {
      //total elements in line 1 = listOfTokens.size()
      //to get degree, leaving the element at last position, count total elements and add degree to tuple using decrements of 1
      for(int i=listOfTokens.size()-1;i>=0;i--)
      {
        //for 1st loop, the value is constant, and degree = 0
        //make a tuple with Coeff and the degree, starting from last index to index 0
        myPClass.addTerm(stod(listOfTokens.at(i)),myPower);
        myPower = myPower + 1;
      }
    line_no = 2;
    }
    else if(line_no == 2)
    {
      for(unsigned i = 0; i < listOfTokens.size(); i++)
      {
        //just for formatting output according to turnin
        if(i<listOfTokens.size()-1)
          cout<<myPClass.evalDerivative(stod(listOfTokens.at(i)))<<" ";
        else
          cout<<myPClass.evalDerivative(stod(listOfTokens.at(i)));
      }
      cout<<endl;
      
      //cout<<myPClass.getDegree();
      //refresh all data for new inputs
      myPower = 0;
      listOfTokens.clear();
      myPClass.clear();
      line_no = 1;
    }
  }
}
