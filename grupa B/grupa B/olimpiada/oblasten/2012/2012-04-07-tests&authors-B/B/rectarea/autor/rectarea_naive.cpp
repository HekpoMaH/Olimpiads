#include<iostream>
using namespace std;

int a[102],b[102],c[102],d[102];
int n;

bool inside(int i, int j)
{
  for(int k=1;k<=n;k++)    
   if(a[k]<=i&&b[k]<=j&&i<c[k]&&j<d[k]) return true;
  return false;
}

int main()
{
  cin >> n;
//  cout << "n=" << n << endl;
  
//  if (n>100) cout << "err 0" << endl;
  
  int j=0;
  for(int i=1;i<=n;i++)
  { 
   int a0,b0,c0,d0;
   cin >> a0 >> b0 >> c0 >> d0;
   if(a0>c0) swap(a0,c0);
   if(b0>d0) swap(b0,d0);
   
//   if(a0<-10000&&b0<-10000&&c0>10000&&d0>10000)
//    cout << "err" << endl;
    
//   if(a0==c0||b0==d0) cout << "err 1: " << i << endl;
   
   if(a0<c0&&b0<d0){j++;a[i]=a0;b[i]=b0;c[i]=c0;d[i]=d0;}
   }
   n=j;
   
//   cout << "n=" << n << endl;
    
   int A=a[1],B=b[1],C=c[1],D=d[1];
   for(int i=2;i<=n;i++)
   {
     if(a[i]<A)A=a[i];
     if(b[i]<B)B=b[i];
     if(c[i]>C)C=c[i];
     if(d[i]>D)D=d[i];        
   }
   
//   cout << A << " " << B << " " << C << " " << D << endl;
   
  int s=0;
  for(int i=A;i<C;i++)
  for(int j=B;j<D;j++)
   if(inside(i,j)) s++;
  
  cout << s << endl;
   
    
    
}

