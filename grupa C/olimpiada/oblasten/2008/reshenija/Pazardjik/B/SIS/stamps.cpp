#include <iostream.h>
int main()
{	int n,s,a[20],t,g=0,k=0;
	cin>>s;
	cin>>n;
	int p=0,h=s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for (i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>=a[j]) 
			{	t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	for(t=n-1;t>=0;t--)
	{for(i=t;i>=0;i--)
	{		while(g<=s)
		{	g=a[i]+g;
			k++;
		}
		if (g-a[i]==s) {p=k-1;}
		g=g-a[i];
		k--;
	}
	if(p<h) h=p;
	g=0;
	k=0;
	}


	cout<<h<<"\n";
		
		
	cout<<"\n";
	return 0;
}