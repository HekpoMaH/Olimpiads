#include<iostream>
#include<fstream>
using namespace std;
int a[524288],n,m,fn,t,mx;
int main()
{
    ifstream fin ("exam.in");
    ofstream fout ("exam.out");
    fin>>n>>m;
    for(int i=0;i<m+n;i++)
    {
        fin>>fn>>t;
        a[fn]+=t;
    }
    for(int i=1;i<=524288;i++)if(a[i]>=119)fout<<i<<endl;
    return 0;
}
