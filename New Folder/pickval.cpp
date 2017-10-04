#include<iostream>
using namespace std;
int main()
{
    long long int a[1000],i=0,brd=0,brv=0;
    do
    {
         i++;
         cin>>a[i];
    }
    while(a[i]!=0);
    i--;
    for(int j=2;j<i;j++)
    {
             if(a[j]>a[j+1]&&a[j]>a[j-1])brv++;
             if(a[j]<a[j+1]&&a[j]<a[j-1])brd++;
    }
    if(a[1]>a[2]&&a[1]>a[i])brv++;
    if(a[1]<a[2]&&a[1]<a[i])brd++;
    if(a[i]>a[i-1]&&a[i]>a[1])brv++;
    if(a[i]<a[i-1]&&a[i]<a[1])brd++;
    cout<<brv<<" "<<brd<<endl;
    system("pause");
    return 0;
}
