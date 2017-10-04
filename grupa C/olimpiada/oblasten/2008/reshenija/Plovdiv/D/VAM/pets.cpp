#include<iostream>
using namespace std;
int main()
{
 char a[5][256],c;
 int i,j,k,br1,br2,n;
 cin>>n>>c;
 for(i=0;i<n;i++)
  cin.getline(a[i],255);
 for(i=0;i<n;i++)
 {
  br1=0;
  br2=0;
  j=0;
  while(a[i][j]!='\0')
  {
   if(a[i][j]=='C'||a[i][j]=='A'||a[i][j]=='T')
   br1++;
   else
   if(a[i][j]=='G'||a[i][j]=='P'||a[i][j]=='I')
   br2++;
   j++;
  }
  if(br1==0 && br2==0)
  cout<<"UFO\n";
  else
  {
   if(br1==br2)
   cout<<"CAT-GPI\n";
   else
   {
    if(br1>br2)
    cout<<"CAT\n";
    else
    cout<<"GPI\n";
   }
  }
 }
 return 0;
}
