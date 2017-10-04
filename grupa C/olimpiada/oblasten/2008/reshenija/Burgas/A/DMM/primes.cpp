#include<iostream.h>
#include<vector>
using namespace std;
unsigned int n;
vector < unsigned int > primes;
bool pr[50002];
int f[50002];

void prime(){
	for (unsigned int i=2;i<=n+20;i++)
		if(pr[i]!=0)
			for(unsigned int j=i+1;j<=n+20;j++)
				if(pr[j] && j % i ==0) pr[j]=0;
			
	for(unsigned int j=2;j<=n+20;j++){
		if(pr[j]!=0)primes.push_back(j);
	}
}


int main(){
	f[0]=1;
	cin>>n;
	for(unsigned int po=0;po<=n+20;po++){
		pr[po]=1;
	}

	prime();
	unsigned int m=primes.size();
	unsigned int temp;
	for(unsigned int k=0;k<m;k++){
		temp=primes[k];
		for(unsigned int i=temp;i<=n;i++)
			f[i]+=f[i-temp];
	}
	unsigned int p;
	for(unsigned int i=primes.size()-1;i>0;i--)
		if(primes[i]>n){ 
			p=primes[i];
		}
	cout<<f[n]%p<<endl;
	return 0;
}
		