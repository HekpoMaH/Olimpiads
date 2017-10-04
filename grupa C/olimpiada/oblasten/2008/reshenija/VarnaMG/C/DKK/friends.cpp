#include <iostream>
using namespace std;
int broi[100000],i=0;
int search(int x,int B[100000],int m)
{int maxbr,br=1;
for(int o=1;o<2*m;o+=2)
{

        if (x==B[o]) {br++;
                     broi[i]=br;
                     i++;
                      search (B[o],B,m);
                      }

}
int j=0;
maxbr=broi[j];
for(int j=1;j<i;j++)
if (maxbr<broi[j]) maxbr=broi[j];
return maxbr;
}
              
int main()
{
    int M,N,pozn,A[100000],I,prov;
    cin>>N>>M;
    for(I=0;I<2*M;I+=2)
    cin>>A[I]>>A[I+1];
    pozn=A[0];
    prov=search(A[0],A,M);
    cout<<prov<<endl;
    
system ("pause");
return 0;
}
