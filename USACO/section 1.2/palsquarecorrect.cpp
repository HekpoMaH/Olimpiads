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
int br=0,a[1000];
int f;
int c[1000],mst=0;
string s,r;

int main()
{
    ifstream fin ("palsquare.in");
    ofstream fout("palsquare.out");
    fin>>b;
    int k;
    for(int x=1;x<=300;x++)
    {
        f=x*x;
        br=0;
        while(f>=b)
        {
            a[br]=f%b;
            br++;
            f/=b;
        }
        if(f!=0){a[br]=f;br++;}
        reverse(a,a+br);
        //cout<<x<<" ";
        //for(int i=0;i<br;i++)cout<<a[i];
        //cout<<endl;
        s="";
        for(int i=0;i<br;i++)
        {
            if((i==0&&a[i]>0)||i>0)
            {
                if(a[i]>=10)s+='A'-10+a[i];
                if(a[i]<10)s+='0'+a[i];
            }
        }
        //cout<<s<<endl;
        r=s;
        reverse(s.begin(),s.end());
        if(r==s)
        {
            s="";
            f=x;
            while(f>=b)
            {
                k=f%b;
                if(k>=10)s+='A'-10+k;
                if(k<10)s+='0'+k;
                f/=b;
            }
            if(f!=0)
            {
                if(f>=10)s+='A'-10+f;
                if(f<10)s+='0'+f;
            }
            reverse(s.begin(),s.end());
            fout<<s;
            fout<<" ";
            fout<<r<<endl;
        }
    }
    return 0;
}