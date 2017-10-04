#include<iostream>
using namespace std;
int main()
{
    long int br=0,a,s=0;
    cin>>a;
    for(int ch=1;ch<=a;ch++)
    {
            if(a%ch==0){s=s+ch;}
    }
    if(s==a){cout<<"chisloto e savarshheno"<<endl;}
    else{cout<<"chisloto ne e savarshheno"<<endl;}
    system("pause");
    return 0;
}
