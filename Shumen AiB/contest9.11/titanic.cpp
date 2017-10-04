#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <map>
using namespace std;
const int worst=INT_MIN;
enum go_t{lef,righ} go;
int n,m;
int x,y;
int xn,yn;
int xm,ym,vm;
bool flip;
map<pair<int,int>,int> db;
bool xcmp(int d1,int d2)
{
    if(d1>d2)return true;
    return false;
}
void init(int *n,int *m){
    scanf("%d %d",n,m);}
int tell(int x,int y)
{
    printf("%d %d %d\n",0,x,y);
    //fflush(stdout);
    scanf("%d",&x);
    return x;
}
void answ(int x,int y)
{
    printf("1 %d %d\n",x,y);
    //fflush(stdout);
    exit(0);
}
void xanswer(int x,int y)
{
    if(flip)swap(x,y);
    answ(x,y);
}
int xtell(int x,int y)
{

    map<pair<int,int>,int>::iterator it;
    if(flip)swap(x,y);
    if(x<0||x>=n||y<0||y>=m)return worst;
    if((it=db.find(make_pair(x,y)))!=db.end())return it->second;
    else return db[make_pair(x,y)]=tell(x,y);
}
void step(int &x,int &y,int &xn,int &yn,int &xm,int &ym)
{
    int cx,cy;
    int cut;
    int cvm;
    cut=x+xn/2;
    cx=cut;cy=-1;
    cvm=worst;
    for(int i=0;i<yn;i++)
    {
        if(xcmp(xtell(cut,y+i),cvm))
        {
            cvm=xtell(cut,y+i);
            cy=y+i;
        }
    }
    if(xcmp(cvm,vm))
    {
        xm=cx,ym=cy,vm=cvm;
        if(xcmp(xtell(cx-1,cy),cvm))go=lef;
        else if(xcmp(xtell(cx+1,cy),cvm))go=righ;
        else xanswer(cx,cy);
    }
    else if(xm<cut)go=lef;
    else go=righ;
    if(go==lef)xn=cut-x;
    else xn-=cut-x+1,x=cut+1;
}
int main()
{
    //setvbuf(stdout, NULL, _IOLBF, 0);
    init(&n,&m);
    x=y=0;
    xn=n;yn=m;
    xm=ym=-1;
    vm=worst;
    while(xn*yn>=1)
    {
        if(xn>yn)
        {
            flip=0;
            step(x,y,xn,yn,xm,ym);
        }
        else
        {
            flip=1;
            step(y,x,yn,xn,ym,xm);
        }
    }
    answ(x,y);
}
