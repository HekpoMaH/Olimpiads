#include<iostream>
#include<vector>
using namespace std;
long n=1,br,a[1024][4],used[1024];
vector<long> sas[1024];
int pr(long x,long y)
{
  long s,s1,s2,s3;
  s1=(a[x][2]-a[x][0])*(a[x][3]+a[x][1]);
  s2=s1;
  s1+=(a[x][0]-a[y][0])*(a[x][1]+a[y][1]);
  s1+=(a[y][0]-a[x][2])*(a[y][1]+a[x][3]);
  if(s1<0) s1=-s1;
  //else if(s1==0) return 1;

  s2+=(a[x][0]-a[y][2])*(a[x][1]+a[y][3]);
  s2+=(a[y][2]-a[x][2])*(a[y][3]+a[x][3]);
  if(s2<0) s2=-s2;
  //else if(s2==0) return 1;

  s=(a[y][0]-a[y][2])*(a[y][1]+a[y][3]);
  s3=s;
  s+=(a[y][2]-a[x][0])*(a[y][3]+a[x][1]);
  s+=(a[x][0]-a[y][0])*(a[x][1]+a[y][1]);
  if(s<0) s=-s;
  //else if(s==0) return 1;

  s3+=(a[y][2]-a[x][2])*(a[y][3]+a[x][3]);
  s3+=(a[x][2]-a[y][0])*(a[x][3]+a[y][1]);
  if(s3<0) s3=-s3;
  //else if(s3==0) return 1;

 // if(x==1&&y==2)
  // cout<<s<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
  if(s1+s2+s3==s||s+s2+s3==s1) return 0;
  if(s+s1+s3==s2||s+s1+s2==s3) return 0;
  if(s+s3==s1+s2) return 1;
  return 0;
}
void popl(long x)
{
  int m;
  if(used[x]==1) return ;
  used[x]=1;br--;
  m=sas[x].size();
  for(int i=0;i<m;i++)
   if(used[sas[x][i]]==0) popl(sas[x][i]);
}
int main()
 {
   while(cin>>a[n][0]>>a[n][1]>>a[n][2]>>a[n][3])
   {
     if(a[n][0]>a[n][2]) {swap(a[n][0],a[n][2]);swap(a[n][1],a[n][3]);}
     n++;
   }
   n-=2;br=n;

   for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    if(pr(i,j)==1) {//cout<<i<<" "<<j<<endl;
                    sas[i].push_back(j);
                    sas[j].push_back(i);
                   }
   for(int i=1;i<=n;i++)
    if(used[i]==0&&pr(n+1,i)==1) popl(i);

   cout<<br<<endl;

   return 0;
 }
