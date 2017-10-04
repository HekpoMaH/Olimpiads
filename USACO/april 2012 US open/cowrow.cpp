#include<iostream>
#include<fstream>
using namespace std;
int n,b[1002];
int ids[1002],nids;
void takeid(int given)
{
    for(int i=1;i<=nids;i++)
    {
        if(given==ids[i])return;
    }
    nids++;
    ids[nids]=given;
}
int mx,cx;
int tryid(int id)
{
    int cblock,last=-1,mb=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==id)continue;
        if(b[i]==last)
        {
            last=b[i];
            cblock++;
        }
        if(b[i]!=last)
        {
            last=b[i];
            cblock=1;
        }
        if(cblock>mb)mb=cblock;
        //cout<<cblock<<" "<<id<<" "<<i<<endl;
    }
    return mb;
}
int main()
{
    ifstream fin("cowrow.in");
    ofstream fout("cowrow.out");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>b[i];
        takeid(b[i]);
    }
    for(int i=1;i<=nids;i++)
    {
        cx=tryid(ids[i]);
        if(cx>mx)mx=cx;
    }
    fout<<mx<<endl;
    return 0;
}