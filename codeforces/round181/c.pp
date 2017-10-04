#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int n;
int a[109];
int set1[109],set2[109],set3[109],br1,br2,br3;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0){br2++;set2[br2]=a[i];}
        if(a[i]>0){br1++;set1[br1]=a[i];}
        if(a[i]==0){br3++;set3[br3]=a[i];}
    }
    if(br1==0)
    {
        br1++;set1[br1]=set2[br2];
        br2--;
        br1++;set1[br1]=set2[br2];br2--;
    }
    if(br2%2==0)
    {
        br3++;set3[br3]=set2[br2];
        br2--;
    }
    cout<<br2;
    for(int i=1;i<=br2;i++)cout<<" "<<set2[i];
    cout<<endl;
    cout<<br1;
    for(int i=1;i<=br1;i++)cout<<" "<<set1[i];
    cout<<endl;

    cout<<br3;
    for(int i=1;i<=br3;i++)cout<<" "<<set3[i];
    cout<<endl;
}

