#include <iostream.h>

int a[1000][1000]={0};
	int N=0, K=0;

int angle(int x, int y)
{
	int i, j, r=0;
	for (i=0; i<K; i++)
		r+=a[x][y+1+i];
	for (j=0; j<K+1; j++)
		r+=a[x+j][y];
	return r;
}

int main()
{
	int s=0, x, y, p;
	cin>>N>>K;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			cin>>a[i][j];
	for (int i=N-1; i>=0; i--)
		for (int j=N-1; j>=0; j--)
			{ 
			p=angle(i, j);
			if (p>=s) {
				s=p;
				x=i;
				y=j; }
			}
	cout<<x+1<<" "<<y+1<<endl;	 	 	 
}
