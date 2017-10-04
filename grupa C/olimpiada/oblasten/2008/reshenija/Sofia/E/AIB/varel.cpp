#include<iostream>
using namespace std;
int main()
{    int V,K,N;
     char a;
     cin>>V;
     cin>>K;
     cin>>N;
     for(int i=0;i<N;i++){
     cin>>a;
     if(a=='+') V=V+K;
     if(a=='-') V=V-K;}
     cout<<V<<endl;          
    return 0;
    }
