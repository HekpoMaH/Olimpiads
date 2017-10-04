#include<iostream>
using namespace std;
int n,k,a[100],e[100],p[100][100],f,s,l;
void BT(int a[100],int e[100],int br,int p[100][100])
{
  if(l==1)return;
  if(br==k+1)
  {
    for(int i=0;i<br;i++)cout<<e[i]<<" ";
    cout<<endl;
    //system("pause");
    l=1;
    return;
  }
  else
  {
    for(int i=1;i<=n;i++)
    {
      if(a[i]==0)
      {
        for(int j=1;j<=n;j++)
        {
          if(p[i][j]==1)
          {
            a[j]++;
          }
        }
        a[i]++;
        e[br]=i;
        br++;
        BT(a,e,br,p);
        for(int j=1;j<=n;j++)
        {
          if(p[i][j]==1)
          {
            a[j]--;
          }
        }
        a[i]--;
        br--;
      }
    }
  }
}
int main()
{
  cin>>n>>k;
  do
  {
    cin>>f>>s;
    p[f][s]=1;
    p[s][f]=1;
  }while(f!=0&&s!=0);
  BT(a,e,0,p);
  return 0;
}

