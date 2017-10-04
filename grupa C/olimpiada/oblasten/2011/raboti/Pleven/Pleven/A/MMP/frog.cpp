#include<iostream>
#include<vector>
using namespace std;
int fsteps;

int n;
int x,y;
pair<int,int>a[15];
vector<long>mas[15];
int main()
{
  cin>>n;
  n*=2;
  for(int i=1;i<=n;i++)
   {
    cin>>x>>y;
    a[i].first=x;
    a[i].second=y;
   }

   a[0].first=0;
   a[0].second=0;
   for(int i=1;i<=n;i++)//za vsqka to4kA ot dadenite pravq razstoqniqta

    {
      for(int j=0;j<=n;j++)//kum vsqka druga to4ka
       {
         int steps=0;
        int q=a[i].first-a[j].first;
        if(q<0)q*=-1;
        int w=a[i].second-a[j].second;
        if(q<0)q*=-1;
        //q,w- pravi rastoqniq m/u to4kite v momentA
         int z=min(q,w);
         steps=z;
         if((max(q,w)-z)%2==0){steps+=(max(q,w)-z); mas[i].push_back(steps);}
         else
         mas[i].push_back(-1);
       }
    }

    ////////////////////////////////////////////
int pos=0;
 for(int i=1;i<=n/2;i++)
 {int mins=999999;
 int tpos=0;
  for(int j=pos+1;j<=n;j++)
  {
    if(mas[j][pos]>-1)
    if(mas[j][pos]<mins){mins=mas[j][pos]; tpos=j;/*tpos- ot kade da trugna sled tova*/}//namiram minimalnata kra4ka
  }
  fsteps+=mins;
  pos=tpos;
 }

/*
    for(int i=1;i<=n;i++)
    { for(int j=0;j<=n;j++)
     cout<<mas[i][j]<<" ";
     cout<<endl;
    }
*/
/*
   for(int i=1;i<=n;i++)
   {
  cout<<
    a[i].first
    <<a[i].second
   <<endl;
   }*/
cout<<fsteps<<endl;
return 0;
}
