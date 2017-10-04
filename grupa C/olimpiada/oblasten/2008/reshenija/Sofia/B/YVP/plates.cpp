#include <iostream>
#include <bvector.h>
#include <stdio.h>
#include <map>
using namespace std;

struct pol
{
       bit_vector A;
       pol() {A.resize(1024);}
};

int N,M;

struct cmp
{
       bool operator() (pol a, pol b)
       {
            for(int i=0; i<N*N; i++)
            {
                    if(a.A[i]>b.A[i]) {return 1;}
                    if(a.A[i]<b.A[i]) {return 0;}
            }
            return 0;
       }
};

map<pol,short int,cmp> Q;

bool cmpp(pol a, pol b)
{
     for(int i=0; i<N*N; i++)
     {
             if(a.A[i]>b.A[i]) {return 1;}
             if(a.A[i]<b.A[i]) {return 0;}
     }
     return 0;
}

pol rot(pol a)
{
   pol res;
   int cnt=0;
   for(int j=0; j<N; j++)
   {
           for(int i=N-1; i>=0; i--)
           {
                    res.A[cnt++] = a.A[i*N+j];
           }
   }
   return res;
}

pol sw(pol a)
{
    pol b;
    for(int i=0; i<=N/2; i++)
    {
            for(int j=0; j<N; j++)
            {
                    b.A[i*N+j]=a.A[(N-i-1)*N+j];
                    b.A[(N-i-1)*N+j]=a.A[i*N+j];
            }
    }
    return b;
}

void print(pol a)
{
     for(int i=0; i<N; i++)
     {
             for(int j=0; j<N; j++)
             {
                     cout<<a.A[i*N+j];
             }
             cout<<endl;
     }
}

pol P[1024];

int main()
{
    cin>>M>>N;
    for(int i=0; i<M; i++)
    {
            for(int j=0; j<N*N; j++)
            {
                    char c;
                    cin>>c;
                    P[i].A[j]=(c=='1')?1:0;
            }
    }
    pol x[8];
    cout<<endl<<endl<<endl;
    for(int i=0; i<M; i++)
    {
            //print(P[i]);
            //print(sw(P[i]));
            x[1]=rot(P[i]);
            x[2]=rot(x[1]);
            x[3]=rot(x[2]);
            x[4]=sw(P[i]);
            x[5]=rot(x[4]);
            x[6]=rot(x[5]);
            x[7]=rot(x[6]);
            for(int k=1; k<8; k++)
            {
                    P[i] = (cmpp(P[i],x[k]))?x[k]:P[i];
            }
            //print(P[i]);
    }
    for(int i=0; i<M; i++)
    {
            Q[P[i]]++;
    }
    map<pol,short int,cmp>::iterator e,i;
    e=Q.end();
    short int maxi=-1;
    for(i=Q.begin(); i!=e; i++)
    {
         maxi = max(maxi, (*i).second);
    }
    cout<<maxi<<endl;
    return 0;
}
