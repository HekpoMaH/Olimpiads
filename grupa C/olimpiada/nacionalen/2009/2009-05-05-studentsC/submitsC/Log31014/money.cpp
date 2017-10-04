/*
TASK:money
LANG:C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int num[201000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&num[i]);
    num[n++]=0;
    sort(num,num+n);
    int l,r,m,max=0;
    for(int i=n-1;i>1;i--)
    {
        l=0;r=i-1;
        while(l<r)
        {
            m=(l+r)/2;
            if(m==0)m++;
            if(num[m]+num[m-1]>num[i])r=m-1;
            else l=m+1;
          // printf("%d %d %d\n",l,r,i);
        //    system("pause");
        }
        //printf("%d %d\n",i,l);
        if(num[l]+num[l-1]>num[i])l--;
        //printf("%d %d\n",i,l);
        if(i-l+1>max)max=i-l+1;
    }
    
    if(max>2) printf("%d\n",max);
    else printf("1\n");
    return 0;
}
