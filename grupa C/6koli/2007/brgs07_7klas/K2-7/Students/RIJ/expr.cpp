#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b,c;
    int x,y,as,bs,ost=0,p;
    cin>>a>>x>>b>>y;
    as=a.size();
    for (int i=as-1;i>=0;i--)
    {
        p=(int)(a[i])-48;
        p=p*x+ost;
        ost=p/10;
        a[i]=(char)((p%10)+48);
    }
    if (ost)
    {
        a=((char)(ost+48))+a;
        as++;
    }
    if(x==0) a='0';
    ost=0;
    bs=b.size();
    for (int i=bs-1;i>=0;i--)
    {
        p=(int)(b[i])-48;
        p=p*y+ost;
        ost=p/10;
        b[i]=(char)((p%10)+48);
    }
    if (ost)
    {
        b=((char)(ost+48))+b;
        bs++;
    }
    ost=0;
    if(y==0) b='0';
    int bss=bs,ass=as;
    for(int i=0;i<ass-bss;i++)
    {
        b='0'+b;
        bs++;
    }
    for(int i=0;i<bss-ass;i++)
    {
        a='0'+a;
        as++;
    }
    c=b;
    for(int i=bs-1;i>=0;i--)
    {
        p=((int)(b[i])-48);
        p=p+((int)(a[i])-48+ost);
        ost=p/10;
        c[i]=(char)((p%10)+48);
    }
    if (ost)
    c=((char)(ost+48))+c;
    cout<<c<<endl;
    return 0;
}
