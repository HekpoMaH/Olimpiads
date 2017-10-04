#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int k;
int br=1;
int a[1000009];
int main()
{
    srand( time(NULL));
    scanf("%d%d",&n,&k);
    if(n/k<=2){cout<<-1<<endl;return 0;}
    for(int i=1;i<=n;i++)
    {
        a[i]=br;
        br++;
        if(br==k+1)br=1;
    }
    if(k==2)
    {
        swap(a[1],a[2]);
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        cout<<endl;
        return 0;
    }
    while(1){
        random_shuffle(a+1,a+k+1);
        int l=1;
        for(int i=1;i<=k;i++)if(a[i]==i){l=0;break;}
        if(l==1)break;}
    
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    cout<<endl;
}
