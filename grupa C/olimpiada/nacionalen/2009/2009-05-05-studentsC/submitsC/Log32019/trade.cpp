/*
TASK:TRADE
LANG:C++
*/
#include <iostream>
#include <cstdio>
using namespace std;
struct route
{
       int a,b;
       float len;
} in[100001];
struct nasl
{
       int a;
       float len;
} sv[100001][2];
float razs[100001];
int main()
{
    int n;
    cin >> n;
    float ans[100001];
    for(int i=0; i<100001; i++)
    razs[i]=100000;
    float sum=0, sumraz=0;
    for(int i=0; i<n; i++){
        cin >> in[i].a >> in[i].b >> in[i].len;}
    for(int i=0; i<n; i++){    
        sum+=in[i].len;
        if(sv[in[i].a][0].a==0)  { sv[in[i].a][0].a=in[i].b; sv[in[i].a][0].len=in[i].len;}
        else{ sv[in[i].a][1].a=in[i].b; sv[in[i].a][1].len=in[i].len;}
        
        if(sv[in[i].b][0].a==0)  { sv[in[i].b][0].a=in[i].a; sv[in[i].b][0].len=in[i].len;}
        else{ sv[in[i].b][1].a=in[i].a; sv[in[i].b][1].len=in[i].len;}
        }
    for(int i=1; i<=n; i++)
    {
            if(sv[i][0].a<sv[i][1].a){ razs[sv[i][0].a-1]=2*(sv[i][1].len-sv[i][0].len);}
            else razs[sv[i][1].a-1]=2*(sv[i][0].len-sv[i][1].len);
    }
    //for(int i=0; i<n-1; i++){ cout << razs[i] << endl;}
    float tk=0;
    float sum2=0;
    for(int i=0; i<n-1; i++)
    {
            if(razs[i]==100000){ cout << "impossible" << endl; return 0;}
            else{ tk+=razs[i]; sum2+=tk; razs[i]=tk; }
    }
    ans[0]=(sum-sum2)/n;
    printf("%4.2f ", ans[0]);
    for(int i=1; i<n-1; i++)
    {
            ans[i]=ans[0]+razs[i-1];
            printf("%4.2f ", ans[i]);
    }
    ans[n-1]=ans[0]+razs[n-2];
    printf("%4.2f\n", ans[n-1]);
    return 0;
}
