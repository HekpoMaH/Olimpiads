#include<iostream>
#include<string>
using namespace std;
string s,s1;
int brwords,h,w,k=60,n; 
int main()
{
 cin>>n; cin.get();
 for(int i=0;i<n-1;i++)
  {
   getline(cin,s);
   s+=' ';
   h=0;
   brwords=0;
   for(int i=0;i<s.size()-1;i++)
    {
     if(s[i]!=' ' && s[i+1]==' ') brwords++;
     if(s[i]!=' ')h++;
    }
   k=60-h;
   s1.clear();
   for(int i=0;i<s.size();i++)
    {
     if(s[i]!=' ') s1+=s[i]; 
     if(brwords==1 && i!=0 && (s[i]==' ' && s[i-1]!=' '))
      {for(int i=1;i<=k;i++) s1+=' '; break;}
     if(i!=0 && (s[i]==' ' && s[i-1]!=' ')) 
      {
       for(int i=0;i<k/(brwords-1);i++) s1+=' ';
       if(k%(brwords-1)>0) {k--; s1+=' ';}       
      } 
    }
   cout<<s1<<endl;
  }
 getline(cin,s);
 s1.clear();
 for(int i=0;i<s.size();i++)
  {
   if(s[i]!=' ') s1+=s[i];
   if(i!=0)
   if(s[i]==' ' && s[i-1]!=' ') s1+=' ';       
  } 
 if(s[s.size()-1]==' ') 
 {
  for(int i=0;i<s1.size()-1; i++) cout<<s1[i];
  cout<<endl;
 }
 else {for(int i=0;i<s1.size(); i++) cout<<s1[i];
  cout<<endl;}
 return 0;    
}
