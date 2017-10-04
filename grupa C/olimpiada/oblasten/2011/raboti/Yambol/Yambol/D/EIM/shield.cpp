#include <iostream>
using namespace std;
int main()
{
  int sekciq1[101],sekciq2[101];
  int n,i;
  int max=0,mi;
  int m,pvis=0,pvis2=0;
  int maxm=0,maxm2=0;

  cin>>n;

  for (i=1;i<=n;i++)
  {
    cin>>sekciq1[i];
    if (sekciq1[i]>max)
    {
      max=sekciq1[i];
      mi=i;
    }
  }

  for (i=1;i<=n;i++)
  {
    cin>>sekciq2[i];
    if (sekciq1[i]+sekciq2[i]>pvis)
    {
      pvis=sekciq1[i]+sekciq2[i];
    }
  }

  for (i=1;i<=n;i++)
  {
    m=abs ( (max-sekciq1[i])+(sekciq2[mi]-sekciq2[i]) );
    if (m>maxm)
    {
    maxm=m;
    }
    m=abs ( (max-sekciq1[i])+(sekciq2[n-mi+1]-sekciq2[n-i+1]) );
    if (m>maxm2)
    {
      maxm2=m;
    }

    if (sekciq1[n-i+1]+sekciq2[n-i+1]>pvis2)
    {
      pvis2=sekciq1[n-i+1]+sekciq2[n-i+1];
    }
  }
  if (pvis2-maxm2<pvis-maxm)
  {
    cout<<pvis-maxm<<endl;
  }
  else
  {
    cout<<pvis2-maxm2<<endl;
  }


  return 0;
}








