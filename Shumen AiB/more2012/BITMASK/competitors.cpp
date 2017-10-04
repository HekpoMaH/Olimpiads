#include<iostream>
using namespace std;
int n,k,mn=5342,minmask;
struct student
{
    int brt;
    int t[25];
};
student s[11];
bool smaller(int m1,int m2)
{
    //cout<<"----------"<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<(m1&(1<<i))<<" "<<(m2&(1<<i))<<endl;
        if(m1&(1<<i) && !(m2&(1<<i)))return true;
        if(!(m1&(1<<i)) && m2&(1<<i))return false;
    }
    return false;
    
}
void check(int bm)
{
    int used[25],br=0;
    for(int i=1;i<=k;i++)used[i]=0;
    for(int i=0;i<n;i++)
    {
        if(bm&(1<<i))
        {
            for(int j=1;j<=s[i+1].brt;j++)used[s[i+1].t[j]]=1;
            br++;
        }
    }
    int fl=1;
    //cout<<bm<<" "<<br<<" ";
    //cout<<endl;
    //for(int i=1;i<=k;i++)cout<<used[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=k;i++)if(used[i]==0)fl=0;
    //cout<<"fl="<<fl<<endl;
    if((fl==1&&br<mn)||(fl==1&&br==mn&&smaller(bm,minmask)))
    {
        mn=br;
        minmask=bm; 
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].brt;
        for(int j=1;j<=s[i].brt;j++)cin>>s[i].t[j];
    }
    for(int mask=1;mask<1<<n;mask++)
    {
        check(mask);
        
    }
    //cout<<(1<<1)<<endl;
    cout<<mn<<endl;
    for(int i=0;i<n;i++)
    {
        if(minmask&(1<<i))cout<<i+1<<" ";
    }
    cout<<endl;
    return 0;
}