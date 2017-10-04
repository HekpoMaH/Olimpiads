#include<iostream>
using namespace std;
int main()
{
    int n,br=0,max=0,l=0;
    cin>>n;
    long long int a,b=-1,d;
    for(int i=1;i<=n;i++)
    {
            cin>>a;
            if(a==b){br++;l=1;}
            else{
                 if(br>max){max=br;d=b;}
                 br=0;
                 }
            b=a;
    }
    if(br>max){max=br;d=b;}
    if(l==0)cout<<"no"<<endl;
    if(l>0)cout<<d<<endl;
    system("pause");
    return 0;
}
