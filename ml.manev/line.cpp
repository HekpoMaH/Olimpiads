#include<bits/stdc++.h>
using namespace std;
int n,w,e;
struct vec
{
    int x,y;
    vec(){};
    vec(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    vec operator+(vec t)
    {
        return vec(x+t.x,y+t.y);
    }
    vec operator-(vec t)
    {
        return vec(x-t.x,y-t.y);
    }
};
int cross(vec a,vec b)
{
    return a.x*b.y-a.y*b.x;
}
int chek(vec M,vec N,vec P,vec Q)
{
    vec PM=M-P;
    vec PN=N-P;
    vec PQ=Q-P;
    if(cross(PQ,PM)*cross(PQ,PN)<=0)return 1;
    return 0;
}
int main()
{
    cin>>n>>w>>e;
    vec P=vec(0,w),Q=vec(100*n,e);
    int br=0;
    //cout<<chek(vec(0,0),vec(1,1),vec(1,0),vec(0,111))<<endl;
    //exit(0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            vec P1=vec(100*i-100,100*j-100);
            vec P2=vec(100*i,100*j-100);
            vec P3=vec(100*i,100*j);
            vec P4=vec(100*i-100,100*j);
            if(chek(P1,P2,P,Q)>0||chek(P2,P3,P,Q)>0||chek(P3,P4,P,Q)>0||chek(P4,P1,P,Q)>0)br++;
        }
    }
    cout<<br<<endl;
}
