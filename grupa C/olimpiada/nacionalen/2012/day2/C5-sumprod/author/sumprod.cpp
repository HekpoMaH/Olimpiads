#include<cstdio>
#include<cstring>
long long int n,m;
long long int num,res,d[1000001];

int main() 
{ 
  scanf("%lld %lld",&n,&m);
  scanf("%lld",&d[0]);
  for(int i=1;i<n;i++)
   {
      scanf("%lld",&num);
      d[i] = (d[i-1] * num) % m; 
      for(int j=i-1;j>0;j--) d[j] = (d[j-1]*num+d[j]) % m;
      d[0] = (d[0] + num) % m;
   }
   res = d[0];
   for(int i=1;i<n;i++) if (d[i] > res) res = d[i];
   printf("%lld\n",res);
}
