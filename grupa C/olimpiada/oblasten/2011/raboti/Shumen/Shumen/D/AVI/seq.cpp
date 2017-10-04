#include<iostream>
using namespace std;
int  main()
{
  double a,b;
  int br=0,mbr=0;
  cin>>a;
  while (b!=0)
  {
    cin>>b;
    if(a<=b){br++;a=b;}
    else
    {
      if(mbr<=br){mbr=br;}
      br=0;
      a=b;
    }
  }
  if(mbr<=br){mbr=br;}
      br=0;
  cout<<mbr+1<<endl;
return 0;
}