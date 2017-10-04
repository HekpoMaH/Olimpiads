#include<iostream>
using namespace std;
int main()
{
    int N, a[20],i,max,max2;
    cin>>N;
    
    if(N<=7)
    {
            for(i=0;i<N;i++)
    {
                    cin>>a[i];
    }
    max=0;
    for(i=0;i<N;i++)
    {
                    if(a[i]>max) max=a[i];   
    }
    
    max2=0;
    for(i=0;i<N;i++)
    {
                    if(a[i]>max2 && a[i]<max) max2=a[i];
    }
    cout<<max+max2+1<<endl;
    }
    
    

    return 0;
}
