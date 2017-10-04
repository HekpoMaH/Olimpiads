#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
string a;
int r,w,brvp,brgp,br;
int main()
{
    cin>>r>>w>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='G'&&brvp<=r){br++;brvp++;}
        if(a[i]=='B'&&brgp<=w){br++;brgp++;}
        if(i!=0&&a[i]!=a[i-1]){brgp=0;brvp=0;}
    }
    cout<<br<<endl;
    return 0;
}