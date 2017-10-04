#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> P ;
int vis[1000+5];
int main()
{
    int m,n,i,j;
    cin>>m>>n;
    P.resize(m*n);
    for( i=0; i<n*m; i++)
    {
            cin>>P[i];
    }
    int end=n;
    for(i=0; i<end; i++)
    {
             for(j=i+1; j<end; j++)
             {
                        int z=0,i1=i,j1=j;
               while(i1<j)
               {
                if(P[i1]!=P[j1] ){z=1;break;}
                i1++;j1++;
               }
               if(z==0){P[j]=P[end-1];end--;}
                 else 
                 {       z=0,i1=i,j1=j+m;
               while(i1<j)
               {
                if(P[i1]!=P[j1] ){z=1;break;}
                i1++;j1++;
               }
               if(z==0){P[j]=P[end-1];end--;}
               
             }
            }
    }
    cout<<end<<endl;
    system("pause");
    return 0;
}

