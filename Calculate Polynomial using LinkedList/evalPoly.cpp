#include<iostream>
#include<vector>
#include<sstream>
#include <string>
#include<iomanip>
#include "ArrayPolynomial.h"
using namespace std;

vector<string> split( const string& s , char delimiter )
   {
       vector<string> tokens;          // vector of tokens
       string token;                   // a single token
       istringstream tokenStream(s);   // an input string stream

       // Tokenize s by grabbing individual tokens
       while( getline( tokenStream , token , delimiter ) )
           tokens.push_back(token);    // add found token

       return tokens;
   }


int main()
{
   ArrayPolynomial pobj;
   string input;                 // input string to hold 1 line from cin
   char   delimiter = ' ';       // what separates tokens in the input string
   vector<string> listOfTokens;  // store tokens of input here
   vector<double> myVals;
   vector<int> valCount;
   ostringstream ss;
   vector<double> finalVect;
   double coeff = 0;
   double exp = 0;
   unsigned line = 1;
   while( getline( cin , input ) )
   {   listOfTokens.clear();
       //cout<<"Reading 1st line" <<endl;
       listOfTokens = split( input , delimiter );
     if(line == 1)//this stores the 1st line. ie coeff and exponents
     {
       for(unsigned i = 0;i<listOfTokens.size();i++)
       {
         coeff = stod(listOfTokens.at(i));  // 1 2 3
         exp = listOfTokens.size() - i - 1; // 0 1 2
         //cout<< coeff<<":"<<exp<<endl;
         pobj.addTerm(coeff,exp);
         //cout<<"Adding Terms"<<endl;
       }
       line = 2;//get ready for line 2 ie values
       //cout<<"process line 2 " <<line<<endl;
       listOfTokens.clear();
     }else
     if(line==2)
     {
       myVals.clear();
       for(unsigned i =0;i<listOfTokens.size();i++)
       {

         myVals.push_back(stod(listOfTokens.at(i)));
       }
       valCount.push_back(listOfTokens.size());
       line = 1;//get ready for line1 again.
       listOfTokens.clear();//refresh the vector

     //line1 data in myPoly[30]
     //line2 values in myVal vector
     //line2 count of values in myVals vector
     //here process the data and store final output into a final vector which would be display at end of input/program
    // cout<<pobj.getDegree();
     //cout<<"Steps";
       for(unsigned i = 0 ; i < myVals.size() ; i ++ )
       {
         ss.str("");
          ss<< pobj.evaluate(myVals.at(i));
          string str = ss.str();
          cout<<str;
         //cout<< pobj.evaluate(myVals.at(i));
         if(i<myVals.size()-1)
         cout<< " ";
       }
       pobj.clear();
       cout<<endl;
       line = 1;
     }
   }
}
