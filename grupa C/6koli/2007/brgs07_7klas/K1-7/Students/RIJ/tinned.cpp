#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    int k;
    cin>>a>>b>>k;
    int as=a.size()-1,bs=b.size()-1;
    int ost=0,sm,j;
    if (as>bs) sm=as;else sm=bs;
    int c[101]={0},d[102]={0};
    for (int i=sm;i>=0;i--)
    if (as==-1)
    {
        j=((int)b[bs])-48+ost;
        if (j>9) {ost=1;j-=10;}
        c[i]=j;
        bs--;
    }
    else if (bs==-1)
    {
        j=((int)a[as])-48+ost;
        if (j>9) {ost=1;j-=10;}
        c[i]=j;
        as--;
    }
    else
    {
        j=((int)b[bs])+((int)a[as])-48-48+ost;
        if (j>9) {ost=1;j-=10;}
        c[i]=j;
        as--;
        bs--;
    }
    if (ost==1)
    {
    for (int i=sm;i>=0;i--)
    c[i+1]=c[i];
    c[0]=ost;
    sm++;
    }
    ost=0;
    for (int i=sm;i>=0;i--)
    {
        j=c[i]*k+ost;
        if (j>9) {ost=j/10;j=j%10;}
        d[i]=j;
    }
    if (ost!=0) cout<<ost;
    for (int i=0;i<=sm;i++)
    cout<<d[i];
    cout<<endl;
    return 0;
}
    
