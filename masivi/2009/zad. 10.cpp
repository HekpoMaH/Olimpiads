#include<iostream>
using namespace std;
int main()
{
    char a[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int br=0;
    for(int i=0;i<n;i++)
    {
            if(a[i]=='a')br++;
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}
