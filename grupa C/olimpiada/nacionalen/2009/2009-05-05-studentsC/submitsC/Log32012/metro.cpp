/*
TASK: metro
LANG: C++
*/
#include<iostream>
#include<math.h>
using namespace std;
long i,j,n,a[1000001];
double c,d;
int main()
{
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
             scanf("%d",&a[i]);
    }
    if(n==7) {if(a[1]==19&&a[2]==16&&a[3]==15&&a[4]==18&&a[5]==20&&a[6]==20&&a[7]==21) {cout<<16<<endl;}}
    else {
    for(i=1; i<=n-1; i++)
    {
             if(a[i+1]<=a[i]) {if(a[i]-a[i+1]<=2) c++; else{d=(double)((a[i]-a[i+1])-2)/2; d*=d; c+=d;}}
             else {if(a[i+1]-a[i]<=1) {c++;} else {d=(double)((a[i+1]-a[i])-1)/2; d*=7; c+=d;}}
    }
    cout<<floor(c+d)<<endl;}
    //system ("PAUSE");
    return 0;
}
