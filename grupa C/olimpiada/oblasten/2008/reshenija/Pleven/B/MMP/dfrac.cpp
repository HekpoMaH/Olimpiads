#include<iostream>
using namespace std;
unsigned long long a,b,p,k,i,z,fl;
int main()
{
    cin>>a>>b>>k>>p;
    while(1==1)
    {
      a*=10;
      z=a/b;
      a%=b;
      i++;
      if(i>=k){cout<<z;p--;}
      if(p==0)break;
      if(a==0){fl=1;break;}
    }
    if(fl==1) for(i=1;i<=p;i++)cout<<0;
    cout<<endl;
//system("pause");    
return 0;
}
