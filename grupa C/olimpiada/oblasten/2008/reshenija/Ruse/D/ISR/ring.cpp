#include<iostream>
using namespace std;
int main()
{
    unsigned long long a[125000];
    bool b[1000000];
    unsigned long long i,n,k,m,br;
    cin>>n>>k;
    for(i=0;i<n;i++){cin>>a[i];b[i]=1;}
    m=n;
    for(i=k-1;i<n;i++){br=0;
                       for(unsigned long long j=i;;j++){br++;if(j>=n-1)j=0;
                                                            if(b[j]==0)br--;
                                                            if(br==k-1){k=a[j];b[j]=0;break;}
                                                            }}
                       for(i=0;i<n;i++)if(b[i]==1){cout<<i+1<<endl;break;}
                       return 0;
}
                                
                       
                                              
