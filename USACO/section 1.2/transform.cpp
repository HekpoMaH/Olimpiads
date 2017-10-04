/*
ID: dobrikg1
PROG: transform
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
string a[11],b[11],c[11];
int n;
bool check()
{
    for(int i=0;i<n;i++)if(b[i]!=c[i])return false;
    return true;
}
void trans90(int k)
{
    string s;
    string s1[11];
    for(int i=0;i<n;i++)
    {
        s="";
        for(int j=n-1;j>=0;j--)
        {
            if(k==0)s+=a[j][i];
            if(k==1)s1[i]+=c[j][i];
        }
        if(k==0)c[i]=s;
    }
    if(k==1)for(int i=0;i<n;i++)c[i]=s1[i];
}
void reflect()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(c[i][j],c[i][n-j-1]);
        }
    }
}
int main()
{
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    fin>>n;
    for(int i=0;i<n;i++){fin>>a[i];c[i]=a[i];}
    for(int i=0;i<n;i++)fin>>b[i];
    if(check()==true){fout<<6<<endl;return 0;}
    trans90(0);
    if(check()==true){fout<<1<<endl;return 0;}
    trans90(1);
    if(check()==true){fout<<2<<endl;return 0;}
    trans90(1);
    if(check()==true){fout<<3<<endl;return 0;}
    for(int i=0;i<n;i++)c[i]=a[i];
    reflect();
    if(check()==true){fout<<4<<endl;return 0;}
    trans90(1);
    if(check()==true){fout<<5<<endl;return 0;}
    trans90(1);
    if(check()==true){fout<<5<<endl;return 0;}
    trans90(1);
    if(check()==true){fout<<5<<endl;return 0;}
    fout<<7<<endl;
    return 0;
}
