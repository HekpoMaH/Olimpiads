#include<iostream>
using namespace std;
long long sums[64];
long long cnts[64];
int digs[64],p;
inline long long sm(long long n)
{
   int ds=0;
   while(n>0)
   {
      digs[ds]=n%p;
      n/=p;
      ++ds;
   }

   long long total=0;
   long long prefix=0;
   cout<<"ds="<<ds<<"\n";
   cout.flush();
   for(int i=ds-1;i>0;--i)
   {
      total+=sums[i-1]*digs[i]+prefix*cnts[i-1]*digs[i]+digs[i]*(digs[i]-1)/2*cnts[i-1];
      prefix+=digs[i];
   }
   total+=prefix*digs[0]+digs[0]*(digs[0]-1)/2;
   
   return total;
}
int main()
{
   long long N,M;
   cin>>M>>N>>p;

   sums[0]=p*(p-1)/2;
   cnts[0]=p;
   for(int i=1;i<64;++i)
   {
      sums[i]=sums[i-1]*p;
      cnts[i]=cnts[i-1]*p;
   }
   for(int i=0;i<64;++i)
      sums[i]*=i+1;
   //for(int i=1;i<=63;i++)cout<<sums[i]<<" "<<cnts[i]<<"\n";
   //cout<<sm(1)<<endl;
   //cout<<sm(2)<<endl;
   //cout<<sm(5)<<endl;
   //cout<<sm(10)<<endl;
   //cout<<sm(20)<<endl;
   //cout<<sm(99)<<endl;
   //cout<<sm(100)<<endl;
   //cout<<sm(101)<<endl;
   cout<<sm(M+N)-sm(M)<<'\n';
}
