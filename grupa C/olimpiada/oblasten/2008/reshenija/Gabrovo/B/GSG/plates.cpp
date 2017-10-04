#include<iostream>
#include<conio.h>
using namespace std;
string plates[1001];
int m,n,nln=0;
void input()
{
     char spot;
     cin>>m>>n;
     for(int pl=0;pl<m*n;pl++)
     {
             cin>>plates[pl];
             }
}
/*void in()
{
     cin>>m>>n;
     for(int pl=0;pl<m;pl++)
     {
             for(int r=0;r<n;r++)
             {for(int k=0;k<n;k++)
             {*/
int main()
{
    input();
    cout<<n<<endl;
    return 0;
}
