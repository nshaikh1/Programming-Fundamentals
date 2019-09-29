#include<iostream>
#include<vector>

using namespace std;
  int count( vector<int> v){
    int iCnt = 0;
    for(int i = 0; i < v.size();i++){
      iCnt = iCnt + 1;
    }
    return iCnt;
  }
 int sum( vector<int> v ){
   int iSum = 0;
   for(int i = 0; i < v.size();i++){
     iSum = iSum + v[i];
   }
   return iSum;
 }
 int min( vector<int> v ){
   int iMin = 0;
   for(int i = 0; i < v.size();i++)
   {
     if(iMin == 0){
       iMin = v[i];
     }else if(v[i] < iMin){
       iMin = v[i];
     }
   }
   return iMin;

 }
 int max( vector<int> v ){
   int iMax = 0;
   for(int i = 0; i < v.size();i++)
   {
     if(iMax == 0){
       iMax = v[i];
     }else if(v[i] > iMax){
       iMax = v[i];
     }
   }
   return iMax;
 }
 float average( vector<int> v ){
   int iSum = 0;float iAvg = 0;
   for(int i = 0; i < v.size();i++){
     iSum = iSum + v[i];
   }
   int iCnt = 0;
   for(int i = 0; i < v.size();i++){
     iCnt = iCnt + 1;
   }
   iAvg = (float) iSum / iCnt;
   return iAvg;
 }

int main(){
int iData = 0;
vector<int> vs;
while(cin>>iData){
  vs.push_back(iData);
  }
cout << "count   = " << count(vs) << endl;
cout << "minimum = " << min(vs) << endl;
cout << "maximum = " << max(vs) << endl;
cout << "sum     = " << sum(vs) << endl;
cout << "average = " << average(vs) << endl;


//cout << "Total Size is: " << vs.size() << endl;
}
