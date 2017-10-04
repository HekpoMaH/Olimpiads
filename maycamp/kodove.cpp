#include<iostream>
#include<algorithm>
using namespace std;
string kod,kod2;
long long sum;
int main()
{
    cin>>kod;
    for(int i=0;i<kod.size();i++)sum+=(kod[i]-'a'+1)*(i+1);
    kod2=kod;
    reverse(kod2.begin(),kod2.end());
    sum%=kod.size();
    if(kod==kod2)sum*=2;
    cout<<sum<<endl;
    return 0;
}