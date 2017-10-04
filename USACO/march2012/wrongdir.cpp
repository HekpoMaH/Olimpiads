#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct dot
{
    long long x,y;
};
dot possible[100004];
unsigned long long spossible;
string given,snew;
long long curdir=1;//0->north;1->east;2->south;3->west
long long curkordx,curkordy;
long long n;
void check()
{
    long long kx=curkordx,ky=curkordy,pos=curdir;
    for(long long i=0;i<n;i++)
    {
        if(snew[i]=='F')
        {
            if(pos==0)ky++;
            if(pos==1)kx++;
            if(pos==2)ky--;
            if(pos==3)kx--;
        }
        if(snew[i]=='R')pos=(pos+1)%4;
        if(snew[i]=='L')
        {
            pos--;
            if(pos==-1)pos=3;
        }
    }
    int fl=1;
    for(unsigned long long i=1;i<=spossible;i++)if(possible[i].x==kx&&possible[i].y==ky){fl=0;break;}
    if(fl==1)
    {
        spossible++;
        possible[spossible].x=kx;
        possible[spossible].y=ky;
    }
}
int main()
{
    ifstream fin ("wrongdir.in");
    ofstream fout("wrongdir.out");
    fin>>given;
    n=given.size();
    for(long long i=0;i<n;i++)
    {
        snew=given;
        if(given[i]=='F')
        {
            snew[i]='R';
            curdir=1;
            curkordx=curkordy=0;
            check();
            curdir=1;
            curkordx=curkordy=0;
            check();
            snew[i]='L';
            curdir=1;
            curkordx=curkordy=0;
            check();
            curdir=1;
            curkordx=curkordy=0;
            check();
        }
        if(given[i]=='R')
        {
            snew[i]='F';
            curdir=1;
            curkordx=curkordy=0;
            check();
            curdir=1;
            curkordx=curkordy=0;
            check();
            snew[i]='L';
            curdir=1;
            curkordx=curkordy=0;
            check();
            curdir=1;
            curkordx=curkordy=0;
            check();
        }
        if(given[i]=='L')
        {
            snew[i]='R';
            curdir=1;
            curkordx=curkordy=0;
            check();
            curdir=1;
            curkordx=curkordy=0;
            check();
            snew[i]='F';
            curdir=1;
            curkordx=curkordy=0;
            check();
            curdir=1;
            curkordx=curkordy=0;
            check();
        }
    }
    fout<<spossible<<endl;
    return 0;
}