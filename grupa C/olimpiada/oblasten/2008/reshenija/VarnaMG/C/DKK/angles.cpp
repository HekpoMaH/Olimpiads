#include <iostream>
using namespace std;
int main()
{
    int A[1000][1000],B,C,N,K,j,i,max_sb=-10000,max_st,max_rd,sb;
    cin>>N;
    cin>>K;
    for (i=0;i<N;i++)
    {for (j=0;j<N;j++)
    cin>>A[i][j];}
    B=K+1;
    C=K+1;
    while (C<N)
          {
          for (i=C;i>=(C-(K+1));i--)
              {
              for (j=C;j>=(C-(K+1));j--)
              sb+=A[i][j];
              }
    
              if (max_sb<sb) {max_sb=sb;
                             max_st=C;
                             max_rd=B;
                             }
              if (max_sb=sb&&max_st>C) {max_sb=sb;
                             max_st=C;
                             max_rd=B;
                             }
              sb=0;
              if (B<N-1&&C==(N-1))
                 {C=K+1;
                 B++;
                 }
              else C++;
           }
    cout<<max_rd<<" "<<max_st<<endl;

return 0;
}

                   
