#include<iostream>
using namespace std;

      int main()
{
      int N, sum1=0, sum2=0, red=0, st=0, K;
      cin >> N >> K;
      int a[N][N], sum3, sum4,k=0,i=1, p , j;
      
      for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
                cin >> a[i][j];
                }     
             for (int i=1;i<=K;i++)
             {
                 sum1=sum1+a[1][i]+a[i][1];
                 }
            
                      sum1=sum1 -a[1][1];
                      
                
              for(p=1;p<=N;p++)
                          
               {  for(j=1;j<=N;j++) 
                    {             k++;
                                    if(K>=k)
                                {
                     
                         sum2= sum2 +a[p][j]+a[j][p];}
                    if(sum2-a[1][1]>=sum1)
                    {
                                       sum1=sum2;
                                        red=p;st=j;
                    }     }     }
                          cout << red << " "<< st <<endl; 
                         // cout << sum1 << sum2;
      system("pause");
      return 0;
      }      
                
