#include <iostream>
int n,t,br=0,s=0;
int marcs[1000];

void load ()
{
cin>>t>>n;
for(int i=1;i<=n;i++)
cin>>marcs[i];
}

void calc(int a[])
{
int c[1000]={0};
int k=1;
while (k<n)
{
	if(c[k]==1)
		{
		c[k]=0;
		s=s-a[k];
		k++;
		}
	else
		{
		c[k]=1;
		s=s+a[k];
		if(s>t-5)br++;
		k=1;
		}
}
}


int main()
{
load();
calc(marcs);
cout<<br;
return 0;
}
