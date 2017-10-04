#include<iostream>
#include<cmath>
using namespace std;
int t[4][3];
int dx,dy;
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
            cout<<i<<" "<<500-i+1<<" "<<t[i][2]<<endl;
            t[i][1]=500-i+1;
            cin>>dx>>dy;i=0;
        }
    }
    for(int i=1;i<=3;i++)
    {
        if(t[i][1]!=500-i+1){cout<<i<<" "<<500-i+1<<" "<<t[i][2]<<endl;t[i][1]=500-i+1;cin>>dx>>dy;}
    }
    cout<<1<<" "<<500<<" "<<dy-1<<endl;
    t[1][2]=dy-1;
    cin>>dx>>dy;
    cout<<2<<" "<<499<<" "<<dy+1<<endl;
    t[2][2]=dy+1;
    cin>>dx>>dy;
    if(t[2][2]-t[1][2]==2)
    {
        cout<<3<<" "<<498<<" "<<dy<<endl;t[3][2]=dy;cin>>dx>>dy;return 0;
    }
    if(dy-t[1][2]==1)
    {
        cout<<3<<" "<<498<<" "<<dy+1<<endl;t[3][2]=dy+1;cin>>dx>>dy;
        cout<<2<<" "<<499<<" "<<dy<<endl;t[2][2]=dy;cin>>dx>>dy;return 0;
    }
    else
    {
        cout<<1<<" "<<500<<" "<<dy-1<<endl;t[1][2]=dy-1;cin>>dx>>dy;
        cout<<3<<" "<<488<<" "<<dy<<endl;t[3][2]=dy;cin>>dx>>dy;return 0;
    }

}
