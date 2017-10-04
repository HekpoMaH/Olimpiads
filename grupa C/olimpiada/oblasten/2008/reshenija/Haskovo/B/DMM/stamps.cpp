#include<iostream>
using namespace std;
int main ()
{   
    int s,n,se=0;
    cin>>s>>n;
    int half=s/2;
    int a[n];
    for(int i=0;i<n;i++) {
            cin>>a[i];
            if (a[i]==s) se=1;
            if (a[i]==half) se=2;
            }
    cout<<se<<endl;   
    return 0;
}
