#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
string a[6];
int main()
{
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
    }
    a[5]="%%%%%%%%%%%%%%%%%%%%%%%%%%";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int br=0;
            if(a[i][j]=='#')br++;
            if(a[i+1][j]=='#')br++;
            if(a[i][j+1]=='#')br++;
            if(a[i+1][j+1]=='#')br++;
            if(br!=2){cout<<"YES"<<endl;return 0;}
        }
    }
    cout<<"NO"<<endl;
}
