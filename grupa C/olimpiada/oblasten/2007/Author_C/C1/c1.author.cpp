#include<iostream>
using namespace std;
int nod(int x, int y)
{
    while (x!=y)
          if (x<y)y-=x; else x-=y;
    return x;      
}
main()
{ int a[100][100], m, n, p=0,q;
  cin>>m>>n;
  for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)cin>>a[i][j];
  int x=0;    
  for (int j=0;j<n;j++)x+=a[0][j];
  for (int i=1;i<m;i++)
  {
      int y=0;
      for (int j=0;j<n;j++)y+=a[i][j];
      x=nod(x,y); 
  }
  for (int j=0;j<n;j++)
  {
      int y=0;
      for (int i=0;i<m;i++)y+=a[i][j];
      x=nod(x,y);
  }
  p=x;
  cin>>m>>n;
  for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)cin>>a[i][j];
  x=0;    
  for (int j=0;j<n;j++)x+=a[0][j];
  for (int i=0;i<m;i++)
  {
      int y=0;
      for (int j=0;j<n;j++)y+=a[i][j];
      x=nod(x,y);
  }
  for (int j=0;j<n;j++)
  {
      int y=0;
      for (int i=0;i<m;i++)y+=a[i][j];
      x=nod(x,y);
  }
  q=x;
  if ((p==1)||(q==1)||nod(p,q)!=1)
  {
      cout<<p<<" "<<q<<endl;
      cout<<"Y"<<endl;
  }
  else
  {
      cout<<p<<" "<<q<<endl;
      cout<<"N"<<endl;
  }
} 

