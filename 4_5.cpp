#include<iostream>
using namespace std;

const char color[7]={'R','O','Y','G','B','I','V'};

int main()
{
	int i,n,t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(i>=0&&i<7)
			cout<<color[i];
		else
		{
			t=(i+1)%4+3;
			cout<<color[t];
		}
	}
	cout<<endl;
	return 0;
}
