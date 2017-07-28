#include<iostream>
using namespace std;

int main()
{
	int i,a,b,c,n,count=0,t;
	cin>>a>>b>>c>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		if(t>b&&t<c)
			count++;
	}
	cout<<count<<endl;
	return 0;	
} 
