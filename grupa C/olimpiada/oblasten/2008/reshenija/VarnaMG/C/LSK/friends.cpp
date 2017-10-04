#include<iostream>
using namespace std;
int main()
{
    int N, M;
    cin>>N>>M;
    int a[N], max,emp, b, i=0;
    for(i=0;i<N;i++)a[i]=0;
    i=0;
    while(i<M)
    {
              cin>>b;
              a[b-1]++;
              cin>>emp;
              i++;
    }
    max=a[0];
    for(i=1;i<N;i++) if(a[i]>max) max=a[i];
    cout<<max<<endl;
    return 0;
}
