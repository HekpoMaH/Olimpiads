#include<iostream>
using namespace std;
int xw,yw,xb,yb,vxw,vyw,vxb,vyb,m,n,k=1;
int main()
{
    cin>>m>>n;
    cin>>xw>>yw>>vxw>>vyw;
    cin>>xb>>yb>>vxb>>vyb;
    if(xw!=xb&&vyw==0&&vyb==0){cout<<"TIE"<<endl;return 0;}
    if(yb!=yw&&vxw==0&&vxb==0){cout<<"TIE"<<endl;return 0;}
    while(1)
    {
        if(xw==m&&vxw==1)vxw=-1;
        if(yw==n&&vyw==1)vyw=-1;
        if(xw==1&&vxw==-1)vxw=1;
        if(yw==1&&vyw==-1)vyw=1;
        if(xb==m&&vxb==1)vxb=-1;
        if(yb==n&&vyb==1)vyb=-1;
        if(xb==1&&vxb==-1)vxb=1;
        if(yb==1&&vyb==-1)vyb=1;
        xw+=vxw;yw+=vyw;
        if(xw==xb&&yw==yb){cout<<"WHITE"<<" "<<k<<endl;return 0;}
        xb+=vxb;yb+=vyb;
        if(xb==xw&&yb==yw){cout<<"BLACK "<<k<<endl;return 0;}
        k++;
    }
}