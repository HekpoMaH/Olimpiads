#include <iostream>
#include <cstdlib>
using namespace std;

int cmp(const void *a,const void*b)
{
    const int *p=(const int *)a;
    const int *q=(const int *)b;
    if(*p>*q)
             return 1;
    if(*p<*q)
             return -1;
    return 0;
}

int main()
{
    int S,N,cnt=0,i,sum;
    int prices[3000];
    cin>>S>>N;
    for(i=0;i<N;i++)
                    cin>>prices[i];
    qsort((void *)prices,N,sizeof(int),cmp);                
    cnt = S/prices[N-1];
    sum=cnt*prices[N-1];
    for(i=0;i<N;i++)
                    if(sum + prices[N-i-2] == S)
                           {
                                           cout<<cnt+1<<endl;
                                           return 0;
                           }
                    else
                        if(sum + prices[N-i-2] < S)
                        {
                               cout<<cnt+1 + (S-(sum - prices[N-i-2]))<<endl;
                               return 0;
                        }
    return 0;
}
