#include<iostream>
#include<cmath>
using namespace std;
int t[4][3];
int dx,dy,mx,my,br,nbr,z1,z2;
int main()
{
    cin>>dx>>dy;//cout<<dx<<" "<<dy<<endl;
    for(int i=1;i<=3;i++)cin>>t[i][1]>>t[i][2];
    //cout<<dx<<" "<<dy<<endl;
    for(int i=1;i<=3;i++)
    {
        //cout<<abs(dx-t[i][1])+abs(dy-t[i][2])<<" "<<dx<<" "<<dy<<" "<<t[i][1]<<" "<<t[i][2]<<endl;
        if(t[i][1]!=dx&&t[i][2]!=dy&&abs(dx-t[i][1])+abs(dy-t[i][2])==2)
        {
            br++;
            if(z1==0)z1=i;
            else z2=i;
        }
        else nbr=i;
    }
    if(br==2)
    {
        if(t[z1][1]==t[z2][1]&&!(t[nbr][2]<=t[z1][2]&&t[nbr][2]<=t[z2][2]))
        {
            cout<<nbr<<" "<<500-t[nbr][1]<<" "<<0<<endl;
            t[nbr][1]=500;
            cin>>mx>>my;
            dx+=mx;dy+=my;

        }
        if(t[z1][2]==t[z2][2]&&!(t[nbr][1]<=t[z1][1]&&t[nbr][1]<=t[z2][1]))
        {
            cout<<nbr<<" "<<0<<" "<<500-t[nbr][2]<<endl;
            t[nbr][2]=500;
            cin>>mx>>my;
            dx+=mx;dy+=my;
        }
    }
    for(int i=1;i<=3;i++)
    {
        //cout<<abs(dx-t[i][1])+abs(dy-t[i][2])<<" "<<dx<<" "<<dy<<" "<<t[i][1]<<" "<<t[i][2]<<endl;
        if(t[i][1]!=dx&&t[i][2]!=dy&&abs(dx-t[i][1])+abs(dy-t[i][2])==2)
        {
            cout<<i<<" "<<-(t[i][1]-(500-i+1))<<" "<<0<<endl;
            t[i][1]=500-i+1;
            cin>>mx>>my;dx+=mx;dy+=my;i=0;
        }
    }
    for(int i=1;i<=3;i++)
    {
        if(t[i][1]!=500-i+1){cout<<i<<" "<<-(t[i][1]-(500-i+1))<<" "<<0<<endl;t[i][1]=500-i+1;cin>>mx>>my;dx+=mx;dy+=my;}
    }
    cout<<1<<" "<<0<<" "<<-(t[1][2]-(dy-1))<<endl;
    t[1][2]=dy-1;
    cin>>mx>>my;dx+=mx;dy+=my;
    cout<<2<<" "<<0<<" "<<-(t[2][2]-(dy+1))<<endl;
    t[2][2]=dy+1;
    cin>>mx>>my;dx+=mx;dy+=my;
    if(t[2][2]-t[1][2]==2)
    {
        cout<<3<<" "<<0<<" "<<-(t[3][2]-dy)<<endl;t[3][2]=dy;cin>>mx>>my;dx+=mx;dy+=my;return 0;
    }
    if(dy-t[1][2]==1)
    {
        cout<<3<<" "<<0<<" "<<-(t[3][2]-(dy+1))<<endl;t[3][2]=dy+1;cin>>mx>>my;dx+=mx;dy+=my;
        cout<<2<<" "<<0<<" "<<-(t[2][2]-dy)<<endl;t[2][2]=dy;cin>>mx>>my;dx+=mx;dy+=my;return 0;
    }
    else
    {
        cout<<1<<" "<<0<<" "<<-(t[1][2]-(dy-1))<<endl;t[1][2]=dy-1;cin>>mx>>my;dx+=mx;dy+=my;
        cout<<3<<" "<<0<<" "<<-(t[3][2]-dy)<<endl;t[3][2]=dy;cin>>mx>>my;dx+=mx;dy+=my;return 0;
    }

}

