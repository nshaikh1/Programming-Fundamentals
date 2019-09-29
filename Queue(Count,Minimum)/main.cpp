#include<iostream>
#include<queue>

using namespace std;

template<class T>
T findMin(T qu)
{
  int min = 0;
  while(!qu.empty())
  {
    if(min==0)
    {
      min = qu.front();
      qu.pop();
    }else if(min>qu.front())
      {
        min=qu.front();
        qu.pop();
      }else
        qu.pop();
    }
  //cout<<min;
  queue<int> que;
  que.push(min);
  // return min;
  return que;
}

template<class T>
T count(T qu)
{
  int cnt = 0;
  while(!qu.empty())
  {
    cnt=cnt+1;
    qu.pop();
  }

  //cout<<cnt<<" ";
  queue<int> que;
  que.push(cnt);
  return que;
}

int main()
{
  queue<int> qu;
  int input = 0;
  while(cin>>input)
  {
    //cout<<input<<endl;
    qu.push(input);
  }
// cout<<count<queue<int>>(qu).front()<<" ";
//cout<<findMin<int>(qu)<<endl;
// count<queue<int>>(qu);
//cout << count<int>(qu).front() << endl;
cout << count<queue<int>>(qu).front();
cout << " "<<findMin<queue<int>>(qu).front()<<endl;

}
