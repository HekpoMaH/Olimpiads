#include<iostream>
using namespace std;
int main()
{int k[100],l[100],n,i,c,m[100],a[100],b[100],d,f[100],r[100],j,z[100];
cin>>n;
for(i=0;i<n;i++){
                cin>>k[i];
                z[i]=k[i];
                while(z[i]!=0){z[i]=z[i]/10;
                            l[i]++;}}
for(i=0;i<n;i++){m[i]=1;
                r[i]=k[i]*k[i];
                for(c=0;c<l[i];c++){
                                m[i]=10*m[i];}
                while(r[i]!=0){r[i]=f[i]/10;
                        d++;
                        }
                a[i]=k[i]%m[i];
                if(2*l[i]>d)b[i]=k[i]/(m[i]+10);
                if((a[i]+b[i])==k[i])j++;
                }
cout<<j;
return 0;
}
