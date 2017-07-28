#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
using namespace std;

//5 3
//sad := 100
//add := sad AND ?
//d := ? OR ?
//qwerer := d XOR add
//da := sad AND ?

const string uk="01";
const int maxm=1000+10;

struct node
{
	string op1,sg,op2;
};

char operateAnd(char x,char y)
{
	if(x=='1'&&y=='1')
		return '1';
	else
		return '0';
}

char operateOr(char x,char y)
{
	if(x=='1'||y=='1')
		return '1';
	else
		return '0';
}

char operateXor(char x,char y)
{
	if(x=='1'&&y=='0')
		return '1';
	else if(x=='0'&&y=='1')
		return '1';
	else
		return '0';
}

int main()
{
	int n,m,i,j,k,sp1,sp2,sp3,sum[2],t;
	char c1,c2,max[maxm],min[maxm];
	string str,name,number,op1,sg,op2;
	map<string,string> mp1;
	map<string,node> mp2;
	map<string,char> mp3;
	vector<string> vt;
	node nd;
	//ios::sync_with_stdio(0);
	cin>>n>>m;
	getchar();
	ios::sync_with_stdio(0);
	for(i=0;i<n;i++)
	{
		getline(cin,str);
		//cout<<"str:"<<str<<endl;
		name=str.substr(0,str.find_first_of(' '));
		//cout<<"name:"<<name<<endl;
		k=str.find_first_of('=');
		sp1=str.find_first_of(' ',str.find_first_of('='));
		if(str[sp1+1]=='0'||str[sp1+1]=='1')
		{
			number=str.substr(sp1+1,sp1+m+1);
			//cout<<"number:"<<number<<endl;
			mp1[name]=number;
		}
		else
		{
			//cout<<"sp1:"<<sp1<<endl;
			sp2=str.find_first_of(' ',sp1+1);
			//cout<<"sp2:"<<sp2<<endl;
			op1=str.substr(sp1+1,sp2-sp1-1);
			//cout<<"op1:"<<op1<<endl;
			sp3=str.find_first_of(' ',sp2+1);
			sg=str.substr(sp2+1,sp3-sp2-1);
			op2=str.substr(sp3+1,str.size()-sp3-1);
			//cout<<"op1:"<<op1<<endl;
			//cout<<"sg:"<<sg<<endl;
			//cout<<"op2:"<<op2<<endl;
			mp2[name]=(node){op1,sg,op2};
			vt.push_back(name);
		}
	}
	for(j=0;j<m;j++)
	{
		for(k=0;k<2;k++)
		{
			for(map<string,string>::iterator it=mp1.begin();it!=mp1.end();it++)
			{
				mp3[it->first]=(it->second)[j];
			}
			sum[k]=0;
			for(i=0;i<vt.size();i++)
			{
				name=vt[i];
				nd=mp2[name];
				if(nd.op1[0]=='?')
					c1=uk[k];
				else
					c1=mp3[nd.op1];
				if(nd.op2[0]=='?')
					c2=uk[k];
				else
					c2=mp3[nd.op2];
				//cout<<"c1:"<<c1<<endl;
				//cout<<"c2:"<<c2<<endl;
				if(nd.sg.compare("AND")==0)
					t=operateAnd(c1,c2);
				else if(nd.sg.compare("OR")==0)
					t=operateOr(c1,c2);
				else 
					t=operateXor(c1,c2);
				mp3[name]=t;
				sum[k]+=t-'0';
			}
			mp3.clear();	
		}
		if(sum[0]>=sum[1])
			max[j]='0';
		else
			max[j]='1';
		//cout<<"max:"<<j<<max[j]<<endl;
		if(sum[0]<=sum[1])
			min[j]='0';
		else
			min[j]='1';
	}
	max[m]='\0';
	min[m]='\0';
	cout<<min<<endl;
	cout<<max<<endl;
	return 0;
}
