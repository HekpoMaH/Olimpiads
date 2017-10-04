/*
TASK:trade
LANG:C++
*/
#include<iostream>
using namespace std;
int fl,s,a[3][100001],b[100001],uk,p[100001];
float d[2][100001],r[100001],otg[100001],ob;
void obh(int w,int v)
{
 int i;   
 //cout<<v<<' '<<uk<<endl;
// system("pause");
   p[v]=1;          
   if(a[0][v]==w)
   { i=a[1][v]; r[uk+1]=d[1][v]; }//cout<<r[uk+1]<<endl;}     
   else
   { i=a[0][v]; r[uk+1]=d[0][v]; }//cout<<r[uk+1]<<endl;}
   uk++;
   b[uk]=v;     
   ob=2*r[uk]-ob;
 if(i==s && v!=s)
 {
  if(uk%2==0)
   if(s==0)
    fl=2;
   else
    fl=1;
  else
   otg[s]=ob/2;   
  return;
 }
 obh(v,i);   
}
int muk[100001];
int main()
{
int n,i,j,k;
float x;
fl=0;
cin>>n;
for(i=1;i<=n;i++)
{
 scanf("%d%d%f",&j,&k,&x);
 a[muk[j]][j]=k;
 d[muk[j]][j]=x;
 muk[j]++;
 a[muk[k]][k]=j;
 d[muk[k]][k]=x;
 muk[k]++;                
}

int br=0;
for(i=1;i<=n;i++)
if(p[i]==0)
{
 uk=0;
 s=i;          
 ob=0;
 obh(i,i);
// for(j=1;j<=uk;j++)
 // cout<<b[j]<<endl;
 //for(j=1;j<=uk;j++)
  //cout<<r[j]<<endl;
  //cout<<endl<<ob<<endl;
 if(fl==1)
 {
   cout<<"impossible"<<endl;
   //system("pause"); 
   return 0;
 }
 else
  if(fl==2)
 {
 cout<<"too many"<<endl;          
 //system("pause");
 return 0;   
 }       
 else
 for(j=2;j<=uk;j++)
  otg[b[j]]=2*r[j-1]-otg[b[j-1]];             
}
for(i=1;i<n;i++)
 printf("%.2lf ",otg[i]);
printf("%.2lf\n",otg[n]); 
//system("pause");
return 0;
}
