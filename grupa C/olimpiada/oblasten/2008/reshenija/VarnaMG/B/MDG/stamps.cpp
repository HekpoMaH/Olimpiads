#include <iostream>
using namespace std;
int sum,s,n,st[3003],o[3003];
int bro=0;
int main()
{
int i,j,p,min=5003,k;

scanf("%d%d",&sum,&n);
s=sum;
for(i=0;i<n;i++)cin>>st[i];
sort(st,st+n);

for(i=n-1;i>=0;i--)
    {
     p=1;
     int x=s;
     int y=(x/st[i]);
     if(!y)y=1;
     for(j=0;j<y;j++)
        if(st[i]<=s || st[i]+st[0] <=s ){o[i]++;s-=st[i];}
        else
            {
             if(o[i]==0)
                        {
                         for(k=n-1;k>=0;k--)if(st[k]<s)break;
                         i=k+1;
                         break;
                         }
             o[i]--;
             s+=st[i];
             break;
             }
     if(s==0)
        {
         bro++;
         if(bro==sum/st[0])break;
         int br=0;
         for(k=0;k<n;k++)br+=o[k];
         if(br<min)min=br;
         for(k=0;k<n;k++)if(o[k])break;
         s+=o[k]*st[k];
         o[k]=0;
         for(;k<n;k++)if(o[k])break;
         s+=st[k];
         o[k]--;
         i=k;
         }
     }
cout<<min<<endl;
return 0;
}
