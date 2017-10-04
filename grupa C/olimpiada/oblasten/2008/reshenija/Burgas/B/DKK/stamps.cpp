#include<iostream>
using namespace std;

int main()
{
	int S,N;
	cin>>S>>N;
	int t,max1=9999;
	int a[3002];
	for (int i=0;i<N;i++)
		cin>>a[i];
			
	
	for (int i=0;i<N;i++)
		{for (int j=0;j<N;j++)
			if (a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
					}
		}
		int ob=0,br,br1;
	for (int pos=0;pos<=N-1;pos++)
		{br1=S%a[pos];
		br=S-br1;
		ob=ob+br;
		if (ob<max1)
			max1=ob;}
			
			
			cout<<max1;

		//system("pause");
cout<<endl;
	return 0;
	}
