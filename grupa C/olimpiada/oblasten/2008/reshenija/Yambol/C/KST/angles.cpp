#include<iostream>
using namespace std;
int main()
{
	int N,K,a[100][100],S,i,j,l,k,p,q,max=0,red=0,stalb=0;
	cin>>N>>K;
	for(i=0;i<N;i++)
	{
		for (j=0;j<N;j++) cin>>a[i][j];
	}
	max=a[0][0];
	for (p=1;p<=K;p++) max=max+a[p][0];
	for (q=1;q<=K;q++) max=max+a[0][q];
	for (i=0;i<N;i++)
	{
    	for (j=1;j<N;j++)
		{
			S=a[i][j];
		    p=j+K;
		    q=i+K;
		    if (p>N-1) p=N-1;
		    for (l=p;l>j;l--) S=S+a[i][l];
		    if (q>N-1) q=N-1;
		    for (k=q;k>j;k--) S=S+a[k][j];
		    if (S>max) {max=S;red=i;stalb=j;}
	   }
	}
	cout<<max<<" "<<red<<" "<<stalb;
	return 0;
}
