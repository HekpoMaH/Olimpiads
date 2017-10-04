#include<iostream>
#include<set>
using namespace std;

long n,br,step,br1,x;
set<unsigned long> s;
set<unsigned long>::iterator it;

int main()
{

 cin>>n;
 for(br=1; br<=n; br++)
 {
   scanf("%d",&x);
   it=s.find(x);
   if(it==s.end()) s.insert(x);
    else s.erase(it);
 }

 bool fl=0;
 for(it=s.begin(); it!=s.end(); it++)
 {
  cout<<(*it);
  if(fl==0) {cout<<" "; fl=1;}
 }
 cout<<endl;





 //system("Pause");
 return 0;
}
