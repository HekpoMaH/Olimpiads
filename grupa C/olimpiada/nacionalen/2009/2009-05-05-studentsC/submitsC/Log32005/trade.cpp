/*
TASK:trade
LANG:C++
*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int n;
bool d[100000];
int a[2][100000];
double c[2][100000],fin[100000];
int f(int k,bool g)
{
    d[k]=true;
    if(g) {
        if(!d[a[0][k]]) {fin[1]+=c[0][k];f(a[0][k],!g);}
        if(!d[a[1][k]]) {fin[1]+=c[1][k];f(a[1][k],!g);}
    }
    else {
        if(!d[a[0][k]]) {fin[1]-=c[0][k];f(a[0][k],!g);}
        if(!d[a[1][k]]) {fin[1]-=c[1][k];f(a[1][k],!g);}
    }
    return 0;
}

int f1(int l)
{
    d[l]=false;
    if(d[a[0][l]]) {fin[a[0][l]]=2*c[0][l]-fin[l];f1(a[0][l]);}
    if(d[a[1][l]]) {fin[a[1][l]]=2*c[1][l]-fin[l];f1(a[1][l]);}
    return 0;
}

main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        int t1,t2;
        double t3;
        cin>>t1>>t2>>t3;
        if(a[0][t1]==0) {
            a[0][t1]=t2;
            c[0][t1]=t3;
        }
        else {
            a[1][t1]=t2;
            c[1][t1]=t3;
        }
        if(a[0][t2]==0) {
            a[0][t2]=t1;
            c[0][t2]=t3;
        }
        else {
            a[1][t2]=t1;
            c[1][t2]=t3;
        }
    }  
    if(n%2==0)
    {
        f(1,true);
        fin[1]-=c[1][1];
        if(fin[1]==0) {cout<<"too many\n";return 0;}           
        else {cout<<"impossible\n";return 0;}
    }
    else {
        f(1,true);
        fin[1]+=c[1][1];
        cout<<fixed<<setprecision(2)<<fin[1];
        f1(1);
    }
    for(int b=2;b<=n;b++) cout<<" "<<fixed<<setprecision(2)<<fin[b];
    cout<<endl;
    return 0;
}
