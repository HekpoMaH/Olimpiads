//ot obiknovenna do verijna
#include<iostream>
using namespace std;
int x,y;
int a[100];
int br;
int nod(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;x=y;y=r;
    }
    return x;

}
int main()
{
    cin>>x>>y;
    do
    {
        a[++br]=x/y;
        x-=(x/y)*y;swap(x,y);
        //int nd=nod(x,y);
        //x/=nd;y/=nd;
        //cout<<x<<" "<<y<<" "<<a[br]<<endl;
    }while(y%x!=0);
    for(int i=1;i<=br;i++)cout<<a[i]<<" ";
    cout<<endl;
}
