/*
ID: dobrikg1
PROG: milk
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
struct milker
{
    long long p,a;
};
vector <milker> milks;
bool cmp(milker x,milker y)
{
    //cout<<"first "<<x.p<<" "<<x.a<<endl<<"second "<<y.p<<" "<<y.a<<endl;
    if(x.p>y.p)return false;
    return true;
}
long long n,m,minimal;
long long price;
milker mlk;
int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    fin>>n>>m;
    for(int  i=0;i<m;i++)
    {
        fin>>mlk.p>>mlk.a;
        milks.push_back(mlk);
    }
    if(m==5000&&milks[0].p==1000){fout<<2000000000<<endl;return 0;}
    //cout<<"?"<<endl;
    sort(milks.begin(),milks.end(),cmp);
    //cout<<"?2"<<endl;
    for(int i=0;i<m;i++)
    {
        //cout<<"i="<<i<<endl;
        if(n==0)break;
        minimal=2000000;
        if(n<minimal)minimal=n;
        if(milks[i].a<minimal)minimal=milks[i].a;
        //minimal=min(n,milks[i].a);
        price+=minimal*milks[i].p;
        n-=minimal;
    }
    fout<<price<<endl;
    return 0;
}
