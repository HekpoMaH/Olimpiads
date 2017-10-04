#include<iostream>
using namespace std;
int main()
{int N,a[10000],br=0,i,max,min=10000,b,sr;
cin>>N;
for (i=0;br<N;i++)
{cin>>a[i];br++;sr--;
if (a[i]>max) max=a[i];
if (a[i]<min) min=a[i];
}

b=a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7];
sr=b-(max+min);
cout<<max+sr+1<<endl;
return 0;
}
