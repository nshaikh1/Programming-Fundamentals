#include<iostream>
#include "Stats.h"

using namespace std;

int main(){
int input = 0;
Stats obj;
while ( cin >> input )
{
  obj.update_val(input);
}
cout << "Sum = " << obj.return_sum();
}