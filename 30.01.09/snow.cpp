#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1){cout<<"*"<<endl;}
    if(n>1)
    {
           for(int i=1;i<=n*2-1;i++)
           {
                   cout<<"*";
                   if(n>2){
                           for(int j=1;j<=n-2;j++)cout<<" ";
           }
           cout<<endl;
           for(int i=1;i<=n-2;i++)cout<<" ";
           for(int i=1;i<=n*2;i++)
           {
                   cout<<"*";
                   if(n>2){
                           for(int j=1;j<=n-2;j++)cout<<" ";
           }
    cout<<endl;
    system("pause");
    return 0;
}
