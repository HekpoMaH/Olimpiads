#include<iostream>
using namespace std;
main()
{int s,i,j,n,f=0,k=0;
cin>>s>>n;
int a[n],b[101],br=0;b[0]=0;
for(i=0;i<n;i++){cin>>a[i];}
sort(a,a+n);
for(i=0;i>-1;i++){f=f+a[n-1];b[br]=b[br]+1;if(f==s){cout<<b[br]<<endl;break;}
if(f>s){f=f-a[n-1];b[br]=b[br]-1;break;}}
for(i=0;i>-1;i++){f=f+a[k];b[br]=b[br]+1;if(f==s){b[br+1]=0;br++;}
                  }
return 0;
}
