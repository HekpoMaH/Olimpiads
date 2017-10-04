#include<bits/stdc++.h>
using namespace std;
string scrudge,patka,kotka;
vector<string> obl[9],ans2;
int prp=99,prs=99;
string prp4,prs4;
string path[6];
int x,uk1,uk2,totmin=999999,luk1,luk2;
vector<string> eqp,eqs;
int givdif(string e,string d)
{
    int i;
    for(i=0;i<e.size();i++)
    {
        if(e[i]!=d[i])return 10-i;
    }
    return 0;
}
bool cmp(string x,string y)
{
    for(int i=0;i<x.size();i++)
    {
        if(x[i]<y[i])return true;
        if(x[i]>y[i])return false;
    }
    return false;
}

int main()
{
    cin>>patka>>scrudge;
    int i,j,k,stk=0;
    //memset(ans,-1,sizeof(ans));
    for(i=1;i<=5;i++)
    {
        cin>>x;
        for(j=1;j<=x;j++)
        {
            cin>>kotka;
            if(i!=5)obl[i].push_back(kotka);
        }
    }
    for(i=2;i<5;i++)sort(obl[i].begin(),obl[i].end(),cmp);
    for(i=0;i<obl[2].size();i++)
    {
        if(givdif(patka,obl[2][i])<prp)
        {
            prp=givdif(patka,obl[2][i]);
            prp4=obl[2][i];
        }
    }
    for(i=0;i<obl[4].size();i++)
    {
        if(givdif(scrudge,obl[4][i])<prs)
        {
            prs=givdif(scrudge,obl[4][i]);
            prs4=obl[4][i];
        }
    }
    int mn[100009],imn[100009],mn2[100009],imn2[100009],l,nuk1,nuk2;
    uk1=uk2=0;
    memset(mn,31,sizeof(mn));
    memset(mn2,31,sizeof(mn2));
    for(i=0;i<obl[3].size();i++)
    {
        for(j=uk1;j<obl[2].size();j++)
        {
            if(givdif(obl[3][i],obl[2][j])<mn[i])
            {
                mn[i]=givdif(obl[3][i],obl[2][j]);
                imn[i]=j;
                nuk1=j;
            }
            if(givdif(obl[3][i],obl[2][j])>mn[i])break;
        }
        uk1=nuk1;
        for(j=uk2;j<obl[4].size();j++)
        {
            if(givdif(obl[3][i],obl[4][j])<mn2[i])
            {
                mn2[i]=givdif(obl[3][i],obl[4][j]);
                imn2[i]=j;
                nuk2=j;
            }
            if(givdif(obl[3][i],obl[4][j])>mn2[i])break;
        }
        uk2=nuk2;
    }
    int sum;
    //cout<<mn[0]<<" "<<mn2[0]<<endl;
    //cout<<mn[1]<<" "<<mn2[1]<<endl;
    //cout<<prp<<" "<<prs<<endl;
    for(int i=0;i<obl[3].size();i++)
    {
        sum=prp+givdif(prp4,obl[3][i])+givdif(obl[3][i],prs4)+prs;
        if(sum<totmin)
        {
            totmin=sum;
            path[1]=prp4;
            path[2]=obl[3][i];
            path[4]=prs4;
        }
        sum=prp+givdif(prp4,obl[3][i])+mn2[i]+givdif(obl[4][imn2[i]],scrudge);
        if(sum<totmin)
        {
            totmin=sum;
            path[1]=prp4;
            path[2]=obl[3][i];
            path[4]=obl[4][imn2[i]];
        }
        sum=givdif(obl[2][imn[i]],patka)+mn[i]+givdif(obl[3][i],prs4)+prs;
        if(sum<totmin)
        {
            totmin=sum;
            path[1]=obl[2][imn[i]];
            path[2]=obl[3][i];
            path[4]=prs4;
        }
        sum=givdif(patka,obl[2][imn[i]])+mn[i]+mn2[i]+givdif(obl[4][imn2[i]],scrudge);
        if(sum<totmin)
        {
            totmin=sum;
            path[1]=obl[2][imn[i]];
            path[2]=obl[3][i];
            path[4]=obl[4][imn2[i]];
        }
    }
    cout<<totmin<<" "<<5<<endl;
    cout<<patka<<endl;
    cout<<path[1]<<endl;
    cout<<path[2]<<endl;
    cout<<path[4]<<endl;
    cout<<scrudge<<endl;
}

