#include<iostream>
#include<string>
using namespace std;
long m,n,i,j,br,l,q,w,r,k,fl;
string a,mas1[30],mas2[30],mas3[30],mas4[30],pl[30000],mas12[30],mas13[30],mas14[30],mas22[30],mas23[30],mas24[30];
string mas32[30],mas33[30],mas34[30],mas42[30],mas43[30],mas44[30];
long sra()
{
   //  4 te osnovni masiva;
 for(i=1;i<=n/2+1;i++)
     mas2[i]=mas1[n-i+1];
    for(i=1;i<=n;i++)
      {
         a=mas1[i];
         reverse(a.begin(),a.end());                
         mas3[i]=a;
      }
     for(i=1;i<=n/2+1;i++)  
      mas4[i]=mas3[n-i+1];    
//sega 6te gi vurtq si4kite
for(i=1;i<=n;i++)
{
   a=mas1[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas12[i][j]=a[j];
} 
 for(i=1;i<=n;i++)
{
   a=mas12[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas13[i][j]=a[j];
} 
  for(i=1;i<=n;i++)
{
   a=mas13[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas14[i][j]=a[j];
}
//osnovniqt e zavurtqn
for(i=1;i<=n;i++)
{
   a=mas2[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas22[i][j]=a[j];
}
for(i=1;i<=n;i++)
{
   a=mas22[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas23[i][j]=a[j];
}
for(i=1;i<=n;i++)
{
   a=mas23[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas24[i][j]=a[j];
}
//mas2 e oburnat
for(i=1;i<=n;i++)
{
   a=mas3[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas32[i][j]=a[j];
}
for(i=1;i<=n;i++)
{
   a=mas32[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas33[i][j]=a[j];
}
for(i=1;i<=n;i++)
{
   a=mas33[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas34[i][j]=a[j];
}
//mas3 e oburnat
for(i=1;i<=n;i++)
{
   a=mas4[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas42[i][j]=a[j];
}
for(i=1;i<=n;i++)
{
   a=mas42[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas43[i][j]=a[j];
}
for(i=1;i<=n;i++)
{
   a=mas43[n-i+1];
   reverse(a.begin(),a.end()); 
 for(j=1;j<=n;j++)
   mas44[i][j]=a[j];
}
//vsi4kite ve4e sa oburnati sega trqbva samo da gi sravnq sus pl i gotovo;
}


int main()
{
    cin>>m>>n;
    for(i=1;i<=n;i++)
     {
      cin>>a;
      pl[i]=a;                
     }
     
for(q=2;q<=m;q++)
{

 for(w=1;w<=n;w++)
  {
    cin>>a;
    pl[q*n-n+w]=a;
    mas1[w]=a;
  }
// do tuka iam plo4kata vkarana v pl sega trea da q srravna s predi6nite i plo4kata v mas 1
sra();
//sega gi sravnqvam sqka sus masivite
for(k=1;k<=q-1;k++)
 {fl=0;
  for(r=1;r<=n;r++)
   if(mas1[r]!=pl[k*n-n+r]){fl=1;break;}
  if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas12[r]!=pl[k*n-n+r]){fl=1;break;}                   
 if(fl==0){br++;break;l=1;}
  for(r=1;r<=n;r++)
   if(mas13[r]!=pl[k*n-n+r]){fl=1;break;}
   if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas14[r]!=pl[k*n-n+r]){fl=1;break;}
    if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas2[r]!=pl[k*n-n+r]){fl=1;break;}
   if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas22[r]!=pl[k*n-n+r]){fl=1;break;}
   if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas23[r]!=pl[k*n-n+r]){fl=1;break;} 
   if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas24[r]!=pl[k*n-n+r]){fl=1;break;}  
    if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas3[r]!=pl[k*n-n+r]){fl=1;break;}
    if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas32[r]!=pl[k*n-n+r]){fl=1;break;}
    if(fl==0){br++;break;l=1;}
    fl=0;
  for(r=1;r<=n;r++)
   if(mas33[r]!=pl[k*n-n+r]){fl=1;break;}
   if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas34[r]!=pl[k*n-n+r]){fl=1;break;}
    if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas4[r]!=pl[k*n-n+r]){fl=1;break;} 
    if(fl==0){br++;break;l=1;}
   fl=0;
  for(r=1;r<=n;r++)
   if(mas42[r]!=pl[k*n-n+r]){fl=1;break;} 
    if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas43[r]!=pl[k*n-n+r]){fl=1;break;}  
    if(fl==0){br++;break;l=1;}
  fl=0;
  for(r=1;r<=n;r++)
   if(mas44[r]!=pl[k*n-n+r]){fl=1;break;}            
   if(fl==0){br++;break;l=1;}
 }
 //if(l==1){m--;q--;}
}
cout<<m-br<<endl;
//system("pause");
return 0;
} 
