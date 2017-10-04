#include <bits/stdc++.h>
using namespace std;
int n,q,s,e,cc,sz,t,l,r;
long long tt[150000];
void inc(int i,long long w){
	for(;i<=n;i|=i+1)
		tt[i]+=w;
}
long long sum(int i){
	long long sum=0;
	for(;i>=0;i=(i&(i+1))-1)
		sum+=tt[i];
	return sum;
}
long long que(int l,int r){
	if(l>r)
		swap(l,r);
	return sum(r)-sum(l-1);
}
int conv(int i){
	if(!cc)
		return i+s;
	else
		return e-i;
}
int main(){
	cin >> n >> q;
	e=n-1;
	for(int i=0;i<n;i++)
		inc(i,1);
	while(q--){
		sz=e-s+1;
		cin >> t >> l;
		if(t==1){
			if(!(sz/2>=l)){
				l=sz-l;
				cc^=1;
			}
			for(int i=1;i<=l;i++)
				inc(conv(2*l-i),que(conv(i-1),conv(i-1)));
			if(!cc)
				s+=l;
			else
				e-=l;
		}
		else{
			cin >> r;
			cout << que(conv(l),conv(r-1)) << endl;
		}
	}
	return 0;
}
