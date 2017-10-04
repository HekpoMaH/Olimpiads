/*
TASK: money
LANG: C++
*/

#include<algorithm>
#include<cstdio>
int n,x[200000],mx=1,a,b;
void find()
{
    a=x[0];
    b=x[1];
    int ind=1;
    for(int i=2;i<n;i++)
        if(b-a>=x[i]-x[i-1])
        {
            a=b;
            b=x[i];
            ind=i;
        }
    int cur=2;
    for(int i=0;i<ind-1;i++)
        if(b<a+x[i])cur++;
    for(int i=ind+1;i<n;i++)
        if(a+b>x[i]&&b<a+x[i])cur++;
    if(cur-2)mx=cur>mx?cur:mx;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    std::sort(x,x+n);
    find();
    printf("%d\n",mx);
    return 0;
}
