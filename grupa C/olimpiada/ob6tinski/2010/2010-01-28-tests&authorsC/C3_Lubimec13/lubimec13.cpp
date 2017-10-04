#include<iostream>
using namespace std;
int main ()
{
    unsigned long long a;
    int n,i,x,flag1,flag3,br=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a;
        flag1=0;
        flag3=0;
        while (a!=0 && flag1!=1)
        {
          x=a%10;
          a=a/10;
          if (x==3) flag3=1;
          if (x==1 && flag3==1) flag1=1;
        }
        if (flag1==1) br++;
    }
    if (br>0) cout<<br<<endl;
    else cout<<"No"<<endl;
    return 0;
}
