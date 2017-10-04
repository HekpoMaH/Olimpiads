#include<bits/stdc++.h>
using namespace std;
int main()
{
    int str[16];
	for(int i=0;i<12;i++)cin>>str[i];
	sort(str, str+12);
	bool l;
	for(int i=0;i<3;i++)
	{
		l=true;
		for(int j=0;j<4;j++)if(str[4*i]!=str[4*i+j])l=false;
		if(l)str[i]=str[4*i];
		else str[i]=0;
	}
	printf("%d\n",str[0]*str[1]*str[2]);
	return 0;
}
