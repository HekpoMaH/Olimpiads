#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    cout<<6<<" "<<30<<endl;
    for(int i=1;i<=30;i++)cout<<(long long)((long long)rand())%6+1<<" ";
    cout<<"\n";
}
