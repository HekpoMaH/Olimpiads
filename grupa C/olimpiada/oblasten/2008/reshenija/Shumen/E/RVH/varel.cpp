#include<iostream>
using namespace std;
int main()
{
    int v,k,n,s;
    char a;
    cin>>v;
    cin>>k;
    cin>>n;
    for(n;n!=0;n--)
    {
                   cin.get(a);
                    if(a=='+')s=v+k;
                    else s=v-k;
    }     
    cout<<s<<endl;
    
    return 0;
}
