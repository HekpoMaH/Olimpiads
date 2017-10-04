#include<iostream>
using namespace std;
int x1[1024],y1[1024],x2[1024],y2[1024];
int a[1024][1024],t[1024];
int f(int g)
{
    //cout<<g<<endl;
    
//system("pause");
 int i;
 t[g]=1;   
 for( i=1;i<=a[g][0];i++)
  if(t[a[g][i]]==0)
   f(a[g][i]);
 return 0;
}

int main()
{
int n,i=1,j,k,a1,a2,b1,b2,c1,c2,ch,zn;
while(cin>>x1[i]>>y1[i]>>x2[i]>>y2[i])
{
i++;
}
n=i-1;
for(i=1;i<=n;i++)
a[i][0]=0;
for(i=1;i<n;i++)
for(j=i+1;j<=n;j++)
{
 a1=y1[i]-y2[i];
 b1=x2[i]-x1[i];
 c1=x1[i]*y2[i]-x2[i]*y1[i];
 a2=y1[j]-y2[j];
 b2=x2[j]-x1[j];
 c2=x1[j]*y2[j]-x2[j]*y1[j];
 if(b1==0)
 {
 ch=-c2*(a1*c2-a2*c1);
 zn=a2*(b2*c1-b1*c2)+b2*(a1*c2-a2*c1);
 }
 else
 {
 ch=-c1*(a1*c2-a2*c1);
 zn=a1*(b2*c1-b1*c2)+b1*(a1*c2-a2*c1);
 }
 int ypm=y1[i],ypg,yvm=y1[j],yvg;
 if(ypm>y2[i])
  ypm=y2[i];
 if(yvm>y2[j])
  yvm=y2[j];
 ypg=y1[i]+y2[i]-ypm;
 yvg=y1[j]+y2[j]-yvm;  
 //cout<<"aaaa"<<y1[j]<<' '<<ypm<<' '<<ypg<<' '<<yvm<<' '<<yvg<<endl<<endl<<endl;
 int xpm=x1[i],xpg,xvm=x1[j],xvg;
 if(xpm>x2[i])
  xpm=x2[i];
 if(xvm>x2[j])
  xvm=x2[j];
 xpg=x1[i]+x2[i]-xpm;
 xvg=x1[j]+x2[j]-xvm;  
 //cout<<"xxx"<<xpm<<' '<<xpg<<' '<<xvm<<' '<<xvg<<endl<<endl<<endl;
 int ch2,zn2;
 if(a1==0)
{
 ch2=b2*ch+c2*zn;
 zn2=-a2*zn;
}
else
{ 
 ch2=b1*ch+c1*zn;
 zn2=-a1*zn;
}
// cout<<a1<<' '<<b1<<' '<<c1<<' '<<a2<<' '<<b2<<' '<<c2<<"          "<<endl;
 if(zn<0)
{ch=-ch; zn=-zn;}
if(zn2<0)
{
 ch2=-ch2; zn2=-zn2;   
}
 //if(zn2!=0)
 // cout<<ch2<<' '<<zn2<<' ';
 //else
 // cout<<'0'<<' ';
 //if(zn!=0)
  //cout<<ch<<' '<<zn<<' ';
 //else
 //cout<<'0'<<' '; 
 //cout<<endl<<endl; 
 //cout<<y1[i]<<y2[i]<<y1[j]<<y2[j]<<endl;
 if(zn*zn2!=0) {
 if( (ch>=ypm*zn) && (ch<=ypg*zn) &&  (ch>=yvm*zn) && (ch<=yvg*zn) )
 if( (ch2>=xpm*zn2) && (ch2<=xpg*zn2) && (ch2>=xvm*zn2) && (ch2<=xvg*zn2) )
 { a[i][a[i][0]+1]=j; a[i][0]++; a[j][a[j][0]+1]=i; a[j][0]++; } }// cout<<i<<' '<<j<<endl; } }
 else
 {
 //cout<<i<<j<<"asdaddadsadasd"<<endl;
 if((a1*b2==b1*a2) && (a1*c2==c1*a2) && (b1*c2==b2*c1) )
 { a[i][a[i][0]+1]=j; a[i][0]++; a[j][a[j][0]+1]=i; a[j][0]++;}// cout<<i<<' '<<j<<endl; }
 }
}
//for(i=1;i<=n;i++)
//{cout<<i<<"  ";
//     for(j=0;j<=n;j++)
//  cout<<a[i][j]<<' ';
// cout<<endl;} 
t[n]=1;
f(n);
int br=0;
//cout<<"asdasd"<<endl;
for(i=1;i<=n;i++)
 if(t[i]==0)
  br++;
//cout<<"ffff"<<endl;  
cout<<br<<endl;  
//system("pause");
return 0;
}
