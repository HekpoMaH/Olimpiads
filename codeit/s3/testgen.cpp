#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int main()
{
    srand(time(NULL));
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=i;
    random_shuffle(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
}
