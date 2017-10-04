#include<bits/stdc++.h>
using namespace std;
int n,bro;
int a[100009],b[100009];
int ansa[100009],ansb[100009];
int uk1,uk2;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];if(i<=n/2)ansa[i]=ansb[i]=1;
    }
    uk1=1;uk2=1;
    while(bro<n)
    {
        //cout<<"uk1="<<uk1<<" uk2="<<uk2<<" "<<a[uk1]<<" "<<b[uk2]<<"\n";
        if(a[uk1]<=b[uk2])
        {
            ansa[uk1]=1;
            uk1++;
            bro++;
        }
        else ansb[uk2]=1,uk2++,bro++;
    }
    //cout<<"uk1="<<uk1<<" uk2="<<uk2<<" "<<ansa[uk1]<<" "<<ansb[uk2]<<"\n";
    for(int i=1;i<=n;i++)cout<<ansa[i];
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<ansb[i];cout<<endl;
}
