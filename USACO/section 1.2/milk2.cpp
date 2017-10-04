/*
ID: dobrikg1
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct farmer
{
    long long b,e;
};
farmer a[5000];
int n;
long long beg,endd,mx1,mx0;
bool cmp(farmer x,farmer y)
{
    if(x.b>y.b)return false;
    if(x.b<y.b)return true;
    if(x.e>y.e)return false;
    return true;
}
int main()
{
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");
    fin>>n;
    for(int i=0;i<n;i++)fin>>a[i].b>>a[i].e;
    sort(a,a+n,cmp);
    //cout<<a[0].b<<" "<<a[0].e<<endl;
    beg=a[0].b;endd=a[0].e;
    for(int i=1;i<n;i++)
    {
        
        if(endd>=a[i].b&&a[i].e>endd)endd=a[i].e;
        if(endd<a[i].b)
        {
            if(endd-beg>mx1)mx1=endd-beg;
            if(a[i].b-endd>mx0)mx0=a[i].b-endd;
            beg=a[i].b;endd=a[i].e;
        }
    }
    if(endd-beg>mx1)mx1=endd-beg;
    fout<<mx1<<" "<<mx0<<endl;
    return 0;
}
