#include<iostream>
using namespace std;

int main(){
		int n;
		cin>>n;
		int k[n],k_j,r=0,f=0;
		bool p[n];
		cin>>k_j;
		for(int i=0;i<n;i++) {cin>>k[i]; p[i]=1;}
		for(int i=0;i<n;i++){
			if(p[i]) f++;
			if(f==k_j){k_j=k[i]; p[i]=0; f=0; r++;}
			if(r==n-1) break;
			if(i==n-1) i=-1;
			}
		for(int i=0;i<n;i++) if(p[i]){cout<<i+1<<endl; break;}
		//system("pause");
		return 0;
}
