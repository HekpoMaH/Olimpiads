#include<iostream>
using namespace std;
int main()
{
    int a,n,max=0;
    cin>>a;
    while(a>0)
    {
              n=a;
              cin>>a;
              if(max<abs(n-a)&&a>0){max=abs(n-a);}
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}
