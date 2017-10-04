#include<iostream>
#include<string>
using namespace std;
int a[102][102];
string s;
int x=1,y=1;
int main()
{
    cin>>s;
    a[x][y]=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='D')
        {
            x++;a[x][y]=a[x-1][y];
        }
        else if(s[i]=='U')x--,a[x][y]=a[x+1][y];
        else if(s[i]=='L')y--,a[x][y]=a[x][y+1];
        else if(s[i]=='R')y++,a[x][y]=a[x][y-1];
        else if(s[i]=='d')x++;
        else if(s[i]=='u')x--;
        else if(s[i]=='r')y++;
        else if(s[i]=='l')y--;
    }
    for(int i=1;i<=26;i++)
    {
        for(int j=1;j<=24;j++)
        {
            if(a[i][j]==1)cout<<"B";
            else cout<<"W";
        }
        cout<<endl;
    }
}
