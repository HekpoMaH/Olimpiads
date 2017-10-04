#include<bits/stdc++.h>
using namespace std;
int n;
int br25,br50,br100;
int main()
{
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==100)
        {
            if(br50!=0&&br25!=0){br50--,br25--;br100++;continue;}
            if(br25>2){br25-=3;br100++;continue;}
            cout<<"NO"<<endl;
            return 0;
        }
        else if(x==50)
        {
            if(br25!=0){br25--;br50++;continue;}
            cout<<"NO"<<endl;
            return 0;
        }
        else br25++;
    }
    cout<<"YES"<<endl;
}
