#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string duma;
int udarenie;

int brg,l,lg,brdt,brdr;
string dumit[30002];
int udart[30005];
string dumir[30002];
int udarr[30005];
void check(string s,int u)
{
    int lc=0,found=0;
    for(int i=0;i<brdr;i++)
    {
        if(s==dumir[i])found=1;
        if(s==dumir[i]&&u==udarr[i])lc=1;
    }
    if(found==0)return;
    if(lc==0)brg++;
}
int main()
{
    cin>>brdr;
    for(int j=0;j<brdr;j++)
    {
        cin>>duma;
        for(int i=0;i<duma.size();i++)
        {
            if(duma[i]>='A'&&duma[i]<='Z')
            {
                udarenie=i;
                duma[i]+=('a'-'A');
                break;
            }
        }
        dumir[j]=duma;udarr[j]=udarenie;
    }
    //cout<<dumir[1]<<endl;
    while(cin>>duma)
    {
        l=0;lg=0;
        for(int i=0;i<duma.size();i++)
        {
            if(duma[i]>='A'&&duma[i]<='Z'&&l==0)
            {
                l=1;
                udarenie=i;
                duma[i]+=('a'-'A');
            }
            if(duma[i]>='A'&&duma[i]<='Z'&&l==1)
            {
                brg++;
                lg=1;
                break;
            }
        }
        //cout<<"d "<<duma<<" "<<l<<" "<<lg<<endl;
        if(l==0)brg++;
        if(lg==0&&l==1)
        {
            dumit[brdt]=duma;
            udart[brdt]=udarenie;
            brdt++;
            //cout<<"A"<<endl;
            //cout<<dumit[brdt-1]<<" "<<udart[brdt-1]<<endl;
        }
    }
    //cout<<brdt<<endl;
    //cout<<dumit[1]<<" "<<dumit[2]<<endl;
    for(int i=0;i<brdt;i++)
    {
        //cout<<dumit[i]<<" "<<brg<<" ";
        check(dumit[i],udart[i]);
        //cout<<brg<<endl;
    }
    cout<<brg<<endl;
    return 0;
}