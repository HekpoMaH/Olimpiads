#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
string s1,s2;
long long bry=0,brd,br,br1y,br1d;
int main()
{
    int n,k;
    cin>>n;
    cin>>s1;
    cin>>s2;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='0'&&s2[i]=='1')brd++,br1d++;
        if(s1[i]=='1'&&s2[i]=='0')bry++,br1y++;
        if(s1[i]=='1'&&s2[i]=='1')
        {
            br++;
            if(br%2==1)bry++,br1y++;
            else brd++,br1d++;
        }
    }
    if(bry==brd||(br1y==br1d-1))cout<<"Draw"<<endl;
    else if(bry>brd)cout<<"First"<<endl;
    else if(bry<brd)cout<<"Second"<<endl;
}

