#include<bits/stdc++.h>
using namespace std;
int s[1<<20],mod=int(1e9)+7,p[1000006];;
int bit(int x)
{
		int br=0;
		while(x)
		{
				br++;
				x&=x-1;
		}
		return br;
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,i,j,a;
		cin>>n;
		p[0]=1;
		for(i=1;i<=n;i++)
		{
				p[i]=p[i-1]+p[i-1];
				if(p[i]>=mod)p[i]-=mod;
				cin>>a;
				s[a]++;
		}
		for(i=0;i<=20;i++)
				for(j=1;j<(1<<20);j++)
						if(j&(1<<i))s[j-(1<<i)]+=s[j];
		int o=p[n]-1;
		for(i=1;i<(1<<20);i++)
		{
				if(bit(i)&1)o-=p[s[i]]-1;
				else o+=p[s[i]]-1;
				if(o>=mod)o-=mod;
				if(o<0)o+=mod;
                                assert(o>=0);
		}
		cout<<o<<'\n';
}
