#include<iostream>
#include<stdio.h>

using namespace std;

int func_get_sum(int a, int arr[])
{
  //loop through the array and sum the elements
  int sum = 0;
  for(int i = 0 ; i < a ; i++ )
  {
    sum = sum + arr[i];
  }
  return sum;
}

int func_count(int a, int arr[])
{
int cnt;
//loop through the array, and increment for each value
  for(int i = 0; i < a; i++)
  {
    cnt = cnt + 1;
  }
}

int func_min(int a, int arr[])
{
  int min = 0;
  //check if its 1st number entered, if yes pass and minimum and compare with remaining values in array
  for( int i = 0; i < a ; i++)
  {
    if(arr[i] < min || min ==0)
    {
      min = arr[i];
    }
  }
  return min;
}

int func_max(int a, int arr[])
{
  int max = 0;
    //check if its 1st number entered, if yes pass and maximum and compare with remaining values in array
  for( int i = 0; i < a ; i++)
  {
    if(arr[i] > max || max ==0)
    {
      max = arr[i];
    }
  }
  return max;
}
float func_avg(int a, int arr[])
{
 float avg = 0;
 int total = 0;
 int count = 0;
 for(int i = 0; i < a; i++)
 {
   total = total + arr[i];
   count = count + 1;
 }
 avg = (double) total / count;
 return avg;
}

int main(){
int myArray[99];
int count = 0, data = 0;
while( cin>>data)
  {
    //Store the input data into an array
    myArray[count] = data;
    //Get total number of elements passed as input
    count = count + 1;
  }
  
  cout << "count   = " << func_count(count, myArray) << endl;
  cout << "minimum = " << func_min(count, myArray) << endl;
  cout << "maximum = " << func_max(count, myArray) << endl;
  cout << "sum     = " << func_get_sum(count, myArray) << endl;
  cout << "average = " << func_avg(count, myArray) << endl;
}


