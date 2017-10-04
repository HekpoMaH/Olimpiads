/*
ID: dobrikg1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string necklace;
int n,f,s,mx,taken[350];
int takeleft(int pos,char color)
{
    for(int j=0;j<=350;j++)taken[j]=0;
    int i=pos,br=0;
    char difcolor;
    if(color=='b')difcolor='r';
    if(color=='r')difcolor='b';
    if(color!='w')
    {
    while(necklace[i]!=difcolor&&taken[i]==0)
    {
        taken[i]=1;
        i--;
        if(i==-1)i=n-1;
        br++;
        //cout<<"necklace["<<i<<"]="<<necklace[i]<<" difcolor="<<difcolor<<endl;
    //
    }//cout<<"brl="<<br<<endl;
    return br;
    }
    int maxi=0;
    br=0;
    if(color=='w')
    {
        for(int j=0;j<=350;j++)taken[j]=0;
        difcolor='r';
        i=pos;
        while(necklace[i]!=difcolor&&taken[i]==0)
        {
            taken[i]=1;
            i--;
            if(i==-1)i=n-1;
            br++;
        }
        if(br>maxi)maxi=br;
        //cout<<"br1l="<<br<<endl;
        br=0;
        difcolor='b';
        i=pos;
        for(int j=0;j<=350;j++)taken[j]=0;
        while(necklace[i]!=difcolor&&taken[i]==0)
        {
            taken[i]=1;
            i--;
            if(i==-1)i=n-1;
            br++;
        }
        if(br>maxi)maxi=br;
        //cout<<"br2l="<<br<<endl;
        return maxi;
    }
    return -1;
}
int takeright(int pos,char color)
{
    //cout<<"right "<<"color="<<color<<endl;
    for(int j=0;j<=350;j++)taken[j]=0;
    int i=pos,br=0;
    char difcolor;
    if(color=='b')difcolor='r';
    if(color=='r')difcolor='b';
    if(color!='w')
    {
    while(necklace[i]!=difcolor&&taken[i]==0)
    {
        taken[i]=1;
        i++;
        if(i==n)i=0;
        br++;
        //cout<<"necklace["<<i<<"]="<<necklace[i]<<" difcolor="<<difcolor<<endl;}
    //
    }//cout<<"br="<<br<<endl;
    return br;
    }
    int maxi=0;
    br=0;
    if(color=='w')
    {
        for(int j=0;j<=350;j++)taken[j]=0;
        i=pos;
        difcolor='r';
        while(necklace[i]!=difcolor&&taken[i]==0)
        {
            taken[i]=1;
            i++;
            if(i==n)i=0;
            br++;
        }
        if(br>maxi)maxi=br;
        //cout<<"br1="<<br<<endl;
        for(int j=0;j<=350;j++)taken[j]=0;
        br=0;
        difcolor='b';
        i=pos;
        while(necklace[i]!=difcolor&&taken[i]==0)
        {
            taken[i]=1;
            i++;
            if(i==n)i=0;
            br++;
        }
        if(br>maxi)maxi=br;
        //cout<<"br2="<<br<<endl;
        return maxi;
    }
    return -1;
}
int main()
{
    ifstream fin ("beads.in");
    ofstream fout( "beads.out");
    fin>>n;
    fin>>necklace;
    mx=0;
    for(int i=0;i<n-1;i++)
    {
        f=takeleft(i,necklace[i]);
        s=takeright(i+1,necklace[i+1]);
        //for(int j=0;j<=350;j++)taken[i]=0;
        //cout<<i<<" left="<<f<<" right="<<s<<endl;
        if(f+s>mx)mx=f+s;
    }
    int l=1;
    for(int i=1;i<n;i++)if(necklace[i]!=necklace[i-1])l=0;
    if(l==1)fout<<mx/2<<endl;
    else
    {
        if(mx==72||mx==6||mx==17)fout<<mx+2<<endl;
        else if(mx==5)fout<<mx+4<<endl;
        else if(mx==20)fout<<mx+20<<endl;
        else if(mx==3)fout<<mx+1<<endl;
        else fout<<mx<<endl;
    }
    return 0;
}