#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n;
int a[1000];
int main()
{
    cin>>n;int mbr=0,br=0,br2=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)br2++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            br=0;mbr=0;
            for(int k=i;k<=j;k++){if(a[k]==0)br++;else mbr++;}
            if(br2+br-mbr>mx)mx=br2+br-mbr;

        }
    }
    cout<<mx<<endl;
}
