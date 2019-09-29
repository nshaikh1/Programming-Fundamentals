#include <iostream>
#include "ArrayBag.h"

using namespace std;


int getSum(vector<int> v){
  int Total = 0;
  int i = 0;
  for(i = 0 ; i < v.size(); i ++)
  {
    
    Total = Total + v[i];
  }
  return Total;
}



int main(){
int iData = 0;
int space = 0;
int iCnt = 1;

vector<int> vsInt;
ArrayBag <int>myBag;

while(cin >> iData){
space = 0;
space = myBag.getCurrentSize();
if( space >= 30 ){
cout << "Cannot add " << iCnt << "; bag already has 30 items in it." << endl;
}else{
myBag.add(iData);
}
iCnt++;
}
vsInt = myBag.toVector();


cout << "The sum of the " << myBag.getCurrentSize() << " items in the bag is " << getSum(vsInt) <<"." << endl;
//The sum of the 10 items in the bag is 55.
}
