#include <cstdio>

using namespace std;

int n,P;
int mas[50000];
int p[5200],w;
int ans[50000];

int rec(int x,int y)
{
	if(2*p[y]>x)
	{
		if(mas[x]) return 1;
		return 0;
	}
	int ans=0;
    for(int i=y;x>=2*p[i];i++)
    {
		ans+=rec(x-p[i],i);
	}
	if(mas[x]) ans++;
	return ans%P;
}

int main()
{
    scanf("%d",&n);
	int br=0;
    for(int i=2;i<50000;i++) mas[i]=i;
    for(int i=2;i<50000;i++)
    {
		if(mas[i])
			for(int j=i*2;j<50000;j+=i)
				mas[j]=0;
    }
    for(int i=2;i<50000;i++) if(mas[i]) p[w++]=i;
    for(;n>p[P];P++){}
    int ans=0;
    for(int i=0;n>=(2*p[i]);i++)
    {
		ans+=rec(n-p[i],i);
	}
	printf("%d\n",ans%p[P]);
    return 0;
}
