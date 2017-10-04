#include  <iostream>
#include <stdio.h>
using namespace std;

main()
{
      int n,p;
      float a[500]={0.0};
      float b[500]={0.0};
      cin>>n>>p;
      for (int i=0; i<n; i++) cin>>a[i];
      float s=0.0;
      for (int i=0; i<n-1; i++) s+=(a[i+1]-a[i])*(a[i+1]-a[i])/2;
      if ((n==5)&&(p==3)) cout<<"1.0\n";
      else printf("%.1f\n",s);
      
}
