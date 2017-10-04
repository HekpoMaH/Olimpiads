#include<iostream>
#include<string>
using namespace std;
string s;
char j;
long m,x,y,n,c,a,t,g,p,i,k,o;
int main()
{
    cin>>n;
    for(m=0;m<=n-1;m++)
    {
       cin>>s;
       k=s.size();
       for(o=0;o<=k-1;o++)
       {
         if(s[o]=='C') c++;
         else
         if(s[o]=='A') a++;
         else
         if(s[o]=='T') t++;
         else
         if(s[o]=='G') g++;
         else
         if(s[o]=='P') p++;
         else
         if(s[o]=='I') i++;
       }
         if(c+a+t==g+p+i && c+a+t!=0) {cout<<"CAT-GPI"<<endl;c=0;a=0;t=0;g=0;p=0;i=0;}
         else
         if(c+a+t>g+p+i) {cout<<"CAT"<<endl;c=0;a=0;t=0;g=0;p=0;i=0;}
         else
         if(c+a+t<g+p+i) {cout<<"GPI"<<endl;c=0;a=0;t=0;g=0;p=0;i=0;}
         else
         if(c+a+t==0 && g+p+i==0 && k!=0) {cout<<"UFO"<<endl;c=0;a=0;t=0;g=0;p=0;i=0;}
    } 
    return 0;
}
    
    

