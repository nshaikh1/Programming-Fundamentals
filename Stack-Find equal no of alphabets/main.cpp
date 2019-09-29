#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{	
	string ip;
	char input;
	stack<char> stk;
	while(cin>>ip)
	{	
		while(!stk.empty())
   {
     stk.pop();
   }
		for(int i=0;i<ip.length();i++)
		{
			if((ip[i]== 'a' || ip[i] == 'b')&&stk.empty()==true)
				stk.push(ip[i]);
			else if(!stk.empty()&&stk.top()=='a'&&ip[i]=='b')
				stk.pop();
			else if(!stk.empty()&&stk.top()=='b'&&ip[i]=='a')
				stk.pop();
			else if(ip[i]=='a'||ip[i]=='b')
				stk.push(ip[i]);			
		}
		if(stk.empty()==true)
		{
			cout<<"\""<<ip<<"\""<<" accepted"<<endl;
		}else
		{
			cout<<"\""<<ip<<"\""<<" REJECTED"<<endl;		
		}
				
	}

	

	return 0;
}