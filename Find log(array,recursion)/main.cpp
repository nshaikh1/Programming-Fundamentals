#include<iostream>
#include<vector>

using namespace std;

void display( int n, int ilog )
{
  if( n>0 ) // non-base case 
  { 
  int tmp = 0;
   if( n/ilog > 0 )
    display( n/ilog,ilog );
    
    if( (n%ilog) >= 10){
      cout<<(char)('A' + ((n%ilog) - 10));  
    }else{
    cout << n%ilog; 
    }
  } 
} // end displayOctal

int main()
{
  int base=0,count=0;
  int myVals = 0;
while(cin>>base>>count){
  //cin>>base>>count;
  int myarray[count];
  for(int i = 0;i<count;i++)
  {
    cin>>myarray[i];
  }
 cout<<"Conversion to base-"<<base<<":"<<endl;   
  for(int i =0;i<count;i++)
  {
    cout<<"  "<<myarray[i]<<":";
    display(myarray[i],base);
    cout<<endl;
  }
  cout<<endl;
  }
  
}