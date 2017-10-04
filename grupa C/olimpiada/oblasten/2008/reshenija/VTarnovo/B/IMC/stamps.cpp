#include<iostream>

using namespace std;

int main()
{
    int p=1,br=0,s,n,a[3000],i,j;
    
    cin>>s>>n;
    
    for(i=0;i<n;i++)cin>>a[i];
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[j]<a[j+1])
               {a[j]=a[j+1]+a[j];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
               }
    
    do
        {while(s>=a[p]){s=s-a[p];br++;
        cout<<s<<" "<<a[p]<<" "<<br<<'\n';}
        p++;}       
    while(s>0);
    
    cout<<br<<'\n';
    
    system("pause");
    return 0;
}
