#include<iostream>
using namespace std;
int main()
{
    long int M, N;
    cin>>N>>M;
    int a1[M], a2[M];
    for(int i=0; i<M; i++)
    cin>>a1[i]>>a2[i];
    int otbori[N+1];
    for(int k=0; k<=N; k++)
    otbori[k]=0;
    int x;
    for(int p=0; p<M; p++)
    {
    x=a1[p];
    otbori[x]++;
    }
    
    int max=0; 
    for(int j=1; j<N; j++)
    {
            if(otbori[j]>max)
            max=otbori[j];
            }
            cout<<max;
    return 0;
}
              
    
