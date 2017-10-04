// P. Hristova

#include<iostream>
using namespace std;

int main()
{
  int c[8], nomer[21],x[21],y[21],t[21], a[7][7],b[8][9];
  int n, i,j,red,col,xt,yt,ind,l,min,imin,q;
  bool flag;
  for(i=1; i<=21; i++)  
  cin >> x[i]>>y[i]>>nomer[i];
  
  for(i = 1; i<=21; i++){
   red=6-y[i];
   col=x[i]+1;
   a[red][col]=nomer[i];
  }
 // kontrolen pe4at
 /* for (i=1; i<=6; i++){
     for (j=1; j<=i;j++)
       cout<<i<<' '<<j<<' '<<a[i][j]<<' ';
       cout<<endl;}
*/    
  for(i=1; i<=7; i++){
   b[i][1]=-1;
   b[i][i+1]=-1;
   b[i][i+2]=-1;        
   } 
  for(i=2; i<=7; i++)
    for(j=2; j<=i; j++)
     b[i][j]=a[i-1][j-1];    
 // kontrolen pe4at  
/*  for (i=1; i<=8; i++){
     for (j=1; j<=9;j++)
       cout<<b[i][j]<<' ';
       cout<<endl;}   */
 for(i=1; i<=8; i++)
   b[8][i]=-1;  
   // start    
  i=7; j=2; ind=1;
  t[ind]=b[i][j];
  flag=false;
 // vzemame 8-te saseda 
  do {
   c[1]=b[i-1][j-1];
   c[2]=b[i-1][j];
   c[3]=b[i-1][j+1]; 
   c[4]=b[i][j-1];
   c[5]=b[i][j+1];
   c[6]=b[i+1][j-1]; 
   c[7]=b[i+1][j];
   c[8]=b[i+1][j+1];      
  // namirane na min sased
   l=1;
   while ((l<=8)&& (c[l]<0)) l++;
   if (l>8) flag= true;
   else { 
        min=c[l]; imin=l;
        for (q=l+1; q<=8; q++)
        if ((c[q]>0) && (min>c[q]))
        {  min=c[q]; imin=q; }
        ind++;
        t[ind]=min;
        b[i][j]=-b[i][j];
        switch (imin) {
        case 1: {i--; j--; break;}
        case 2: {i--; break;}
        case 3: {i--; j++; break;}
        case 4: {j--; break;}
        case 5: {j++; break;}
        case 6: {i++; j--; break;}
        case 7: {i++; break;}
        case 8: {i++; j++; break;}
        }                                                     
    }
  } while (!flag);
  for (i=1; i<=ind-1; i++)     
  cout << t[i]<<' ' ;
  cout <<t[ind]<<endl;
  return 0;
}
