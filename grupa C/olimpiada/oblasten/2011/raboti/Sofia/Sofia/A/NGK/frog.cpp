#include <iostream>
#include <cstdio>
using namespace std;

int inf = 100000;
int a[16][16],n;
int b[16][2];

int calc (int q, int e) {
	if (q==e) return inf;
	int qx=b[q][0]-b[e][0];
	int qy=b[q][1]-b[e][1];

	if (qx<0) qx=-qx;
	if (qy<0) qy=-qy;

	if (qx>qy) return qx;
	return qy;
}


int variation(int c,int k) {
	int buf[10];


	for (int i=0;i<10;i++) buf[i]=0;
	for (int i=1;i<=k;i++) buf[i]=i;
	buf[0]=buf[1]=0;
	bool ch=true;
	int res=inf;
	int cres=0;
	while (buf[k+1]==0) {
		ch=true;
		//printf("A");
		buf[1]++;
		for (int i=1;i<=k;i++) {
			if (buf[i]>c) {
				buf[i+1]++;
				buf[i]-=c;
			}
		}
		if (buf[k+1]!=0) break;
		cres=0;
		for (int i=1;i<=k;i++) {
			for (int j=1;j<=k;j++) {
				if (buf[i]==buf[j] && i!=j) {
					ch=false;
					break;
				}
			}
			if (!ch) break;
		}
		if (ch) {
			cres=0;
			//for (int i=1;i<=k;i++) cout<<buf[i]<<" ";
			for (int i=1;i<=k;i++)  {
				//cout<<buf[i-1]<<" "<<buf[i]<<"\n";
				cres+= a[buf[i-1]][buf[i]];
			}
			//cout<<"\t"<<cres<<"\n";
			if (cres<res) res=cres;
		}


	}


	return res;
}


int main() {
	int x,y;
	int m;
	int r=1;
	cin>>m;
	int n=2*m;
	for (int i=0;i<16;i++)
		for (int j=0;j<16;j++)
			a[i][j]=inf;

	for (int i=1;i<=n;i++) {
		cin>>x>>y;
		if ((x+y)%2==1) continue;
		b[r][0]=x;
		b[r][1]=y;
		r++;
	}
	n=r;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			a[i][j]=a[j][i]=calc(i,j);
		}
	}
	/*
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"\n";


	for (int k=0;k<n+1;k++) {
		for (int i=0;i<n+1;i++) {
			for (int j=0;j<n;j++) {
				if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	cout<<variation(n,m)<<"\n";
	return 0;
}
