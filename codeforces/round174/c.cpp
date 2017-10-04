#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
long long n,t,fff,ff;
long long sumel,ad,el[220000],uk=1,used[202000];
int main()
{
    cin>>n;el[1]=uk;//ios::sync_with_stdio(false);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&t);
        if(t==3)sumel-=el[uk]+used[uk],used[uk-1]+=used[uk],uk--;
        if(t==2)
        {
            scanf("%lld",&fff);uk++;el[uk]=fff;used[uk]=0;sumel+=fff;
        }
        if(t==1)
        {
            scanf("%lld%lld",&fff,&ff);
            sumel+=fff*ff;
            used[fff]+=ff;
        }
        cout<<setiosflags(ios::fixed)<<setprecision(6)<<(double)sumel/uk<<endl;
        printf("%.6lf\n",(double)sumel/uk);
    }
}


