#include <cstdio>
#include <stack>
using namespace std;
void Read();
void Solve();

int n,p;
int br=0;
char pr[50022];

int main()
{
	Read();
	Solve();
	
	return 0;
}

void Read()
{
	scanf("%d",&n);
	int i;
	
	for(i=2;i<25011;i++)
	{
		if(!pr[i]) for(int j=i*2;j<=50022;j+=i)
			pr[j]=1;
	}
	
	i=n;
	while(pr[++i]);
	p=i;
	
//	if(!pr[n]) br++;
}

void Solve()
{
	int csum=2;
	stack<int> s;
	
	s.push(2);
	
	while(!s.empty())
	{
		if(csum<n)
		{
			s.push(s.top());
			csum+=s.top();
		}
		if(csum==n) ++br;
		if(csum>=n)
		{
			csum-=s.top();
			s.pop();
			int x=s.top();
			csum-=x;
			s.pop();
			while(pr[++x]);
			if(s.empty() && x>(n/2)) break;
			s.push(x);
			csum+=x;
		}
	}
	
	printf("%d\n",br);
}
