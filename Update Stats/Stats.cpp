#include<iostream>
#include "Stats.h"

using namespace std;

void Stats::update_val(int x){
  sum = sum + x;
}

int Stats::return_sum(){
return sum;
}
