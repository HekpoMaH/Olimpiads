#include <cstdio>
#include <iostream>
#include <map>
#include <iterator>
using namespace std;
unsigned int x,n,c[2];
map<unsigned int,bool>a;
int main()
{scanf("%d",&n);
for(int i=1;i<=n;i++)
{scanf("%d",&x);
        if(a[x]==true)a.erase(x);
        else a[x]=true;
}
map<unsigned int,bool>::iterator it;
x=0;
for(it=a.begin();it!=a.end();it++)
c[x++]=(*it).first;
cout<<c[0]<<" "<<c[1]<<endl;
// system("pause");
    return 0;
}
