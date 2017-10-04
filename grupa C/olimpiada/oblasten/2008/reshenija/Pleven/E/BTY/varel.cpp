#include<iostream>
using namespace std;
int main(){
    int p,k,n;
    int i;
    char ch;
    cin>>p;
    cin>>k;
    cin>>n;
    for(i=1;i<=n;i++)
    { cin>>ch;
    if(ch=='+'){ p=p+k;}
    if(ch=='-'){ p=p-k;}
}
cout<<p<<endl;
return 0;
}

