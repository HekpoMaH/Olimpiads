/*
ID: dobrikg1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct giver
{
    string name;
    int fmoney;
    int curmoney;
    int pgiv;
    string given[10];
};
giver g[11];
int np,ind,indp,pzd;
string gn,pn;
int findnum(string id)
{
    for(int i=1;i<=np;i++)if(g[i].name==id)return i;
    return -1;
}
int main()
{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    fin>>np;
    for(int i=1;i<=np;i++)
    {
        fin>>g[i].name;
    }
    for(int i=1;i<=np;i++)
    {
        
        fin>>gn;
        ind=findnum(gn);
        fin>>g[ind].fmoney>>g[ind].pgiv;
        if(g[ind].pgiv!=0)
        {
            pzd=g[ind].fmoney/g[ind].pgiv;
            g[ind].curmoney+=g[ind].fmoney%g[ind].pgiv;
        }
        for(int j=1;j<=g[ind].pgiv;j++)
        {
            fin>>pn;
            indp=findnum(pn);
            //cout<<"pzd="<<pzd<<endl;
            g[indp].curmoney+=pzd;
        }
    }
    for(int i=1;i<=np;i++)
    {
        //cout<<g[i].fmoney<<" "<<g[i].curmoney<<endl;
        fout<<g[i].name<<" "<<g[i].curmoney-g[i].fmoney<<endl;
    }
    return 0;
}
