#include <iostream>
using namespace std;
int main ()
{
    int s,N,a[3000],br=0,br1;
    cin>>s>>N;
    for (int i=0;i<N;i++)
        cin>>a[i];
    sort(a,a+N);
    for (int i=N-1;i>=0;i--)
        if (s%a[i]==0) 
        {
            br1=s/a[i];
            break;
        }   
    while (s!=0)
    {
        if (s-a[N-1]>=0) 
        {
            s=s-a[N-1];
            br++;
        }
        else 
            N--;
    }
    if (br>br1) swap(br1,br);
    cout<<br<<endl; 
    return 0;
}
