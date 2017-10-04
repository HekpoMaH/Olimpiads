#include<iostream>
using namespace std;
typedef struct{
        int n;
        int st;
        }player;
int main()
{
    player p[100001];
    int n,winner,i,j,k[100];
    cin>>n>>k[1];
    for(i=1;i<=n;i++){
    p[i].n=i;
    p[i].st=1;
    }
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=k[i];j++)
    {
    if(p[j].st!=1)
    {
                  j++;
                  k[i]++;
    }
    else if((p[j].st==1)&&(j==k[i]))
    {
         p[j].st=-1;
         break;
    }                
    }
    cin>>k[i+1];
    }       
    for(i=1;i<=n;i++){
                      if(p[i].st==1)winner=p[i].n;
                      }
                      cout<<winner<<endl;
                      system("pause");
                      return 0;
                      }
