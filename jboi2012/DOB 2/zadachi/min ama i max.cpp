#include<iostream>
using namespace std;
int main()
{
    long int a,min=99999,max=0;
    cin>>a;
    while(a!=0)
    {
               if(a>max){max=a;}
               if(a<min){min=a;}
               cin>>a;
    }
    if(min==99999 && max==0){cout<<"NO"<<endl;}
    else{cout<<max<<endl<<min<<endl;}
    system("pause");
    return 0;
}
