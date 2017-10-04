/*
ID: dobrikg1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
int b;
int br=0,a[100];
int f;
int c[100],mst=0;
string s,r;

int main()
{
    ifstream fin ("palsquare.in");
    ofstream fout("palsquare.out");
    fin>>b;
    for(int x=1;x<=300;x++)
    {
        f=x;
        br=0;
        mst=0;
        while(f>=b)
    {
        a[br]=f%b;
        br++;
        f/=b;
    }
    if(f!=0){a[br]=f;br++;}
    reverse(a,a+br);
    for(int i=0;i<100;i++)c[i]=0;
    for(int i=0;i<br;i++)
    {
        for(int j=0;j<br;j++)
        {
            c[i+j]+=a[i]*a[j];
            if(mst<i+j)mst=i+j;
        }
    }
    for(int i=mst;i>=1;i--)
    {
        c[i-1]+=c[i]/b;
        c[i]%=b;
    }
    s="";
    
    if(c[0]>=b)
    {
        if(c[0]/b>=10)s+='A'-10+c[0]/b;
        if(c[0]/10<10)s+='0'+c[0]/b;
        c[0]%=10;
    }
    for(int i=0;i<=mst;i++)
    {
        if(c[i]>=10)s+='A'-10+c[i];
        if(c[i]<10)s+='0'+c[i];
    }//cout<<"s="<<s<<endl;
    r=s;
    reverse(s.begin(),s.end());
    if(r==s)
    {
        s="";
        for(int i=0;i<br;i++)
        {
            if(a[i]>=10)s+='A'-10+a[i];
            if(a[i]<10)s+='0'+a[i];
        }
        fout<<s;
        fout<<" ";
        fout<<r<<endl;
    }
    }
}