#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

main()
{
      int n,p;
      float b[500],c[500],a[501];
      cin>>n>>p;
      for (int i=1;i<=n;i++) cin>>a[i];
      for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
      for (int i=1;i<n;i++) c[i]=b[i];
      sort(c,c+n-1);
      
      int cent;
      cent=n-p;
      for (int i=1;i<n;i++) 
          if (b[i]>=c[cent]) b[i]=0;
      //for (int i=1;i<n;i++) cout<<b[i]<<" ";
      float sum=0;
      int j=1,t=0;
      float avg[500];
      int g[500];
      for (int i=1;i<n+1;i++)
          {sum+=a[i];t++;g[i]=j;if(b[i]==0) {avg[j]=sum/t;j++;t=0;sum=0;};};
          avg[j]=sum/t;j++;t=0;sum=0;  
      float d=0;
      for (int i=1;i<n+1;i++) 
      d=d+(avg[g[i]]-a[i])*(avg[g[i]]-a[i]);
      printf("%.4f",d);
      cout<<endl;
      }
