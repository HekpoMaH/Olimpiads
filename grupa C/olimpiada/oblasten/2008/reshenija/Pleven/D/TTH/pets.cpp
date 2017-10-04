#include<iostream>
#include<string>
using namespace std;
long n,cat,gpi;
string a[10000];
int main()
{
    cin>>n;
    for(long i=0;i<n;i++)
    {
            cin>>a[i];
    }
    for(long i=0;i<n;i++)
    {
            cat=0;
            gpi=0;
            for(long j=0;j<a[i].size();j++)
            {
                    if(a[i][j]=='C' || a[i][j]=='A' || a[i][j]=='T'){cat++;}
                    if(a[i][j]=='G' || a[i][j]=='P' || a[i][j]=='I'){gpi++;}
            }
    if(cat>gpi){cout<<"CAT"<<endl;}
    if(cat<gpi){cout<<"GPI"<<endl;}
    if(gpi==cat && gpi!=0){cout<<"CAT-GPI"<<endl;}
    if(gpi==0 && cat==0){cout<<"UFO"<<endl;}
    }
    //system("PAUSE");
    return 0;
}
