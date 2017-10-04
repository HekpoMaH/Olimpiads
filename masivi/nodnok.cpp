#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
        cin>>a[i];
    }
    int p=1;
    for(int i=0;i<=n-1;i++)
    {
        p=p*a[i];
    }
    p=abs(p); 
    int nod;
    a[0]=abs(a[0]),a[1]=abs(a[1]);
    do
    {
              if(a[0]>a[1]){a[0]=a[0]-a[1];}
              else{a[1]=a[1]-a[0];}
    }
    while(a[0]!=a[1]);
    nod=a[0];
    int h;
    for(int i=2;i<=n-1;i++)
    {
            h=nod;
            a[i]=abs(a[i]);
            do
            {
              if(nod>a[i]){nod=nod-a[i];}
              else{a[i]=a[i]-nod;}
             }
              while(nod!=a[i]);
    }         
    cout<<nod<<endl;
    long long int nok;
    nok=p/nod;
    cout<<nok<<endl;
    system("pause");
    return 0;
}
