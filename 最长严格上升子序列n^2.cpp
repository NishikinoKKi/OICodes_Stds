#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int in[5050][3];
int main()
{
	int i,tmp;
	cin>>i;
	memset(in,0,sizeof(in));
	for(int t=1;t<=i;t++) cin>>in[t][1];
	for(int t=i;t>0;t--) in[t][2]=1;
	for(int t=i;t>0;t--)
	{
		tmp=0;
		for(int t2=t+1;t2<=i;t2++)
		{
			if(in[t2][1]>in[t][1]&&in[t2][2]>tmp) tmp=in[t2][2];
		}
		in[t][2]+=tmp;
	}
	int mx=0;
	for(int t=1;t<=i;t++) mx=in[t][2]>mx?in[t][2]:mx;
	cout<<mx<<endl;
	return 0;
}
