#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
string tr(""),cr(""),dr("");
char xr[100];
long long pow(int fr)
{int ir;
long long rr=10;
for(ir=1;ir<fr;ir++)
rr*=10;
return rr;
}
bool only_0()
{int ir,sizer;
sizer=cr.size();
for(ir=0;ir<sizer;ir++)
if(cr[ir]!='0') return false;
return true;
}
void fill_0(int nr)
{int ir;
cr="";
for(ir=1;ir<=nr;ir++)
cr+='0';
}
int main()
{long long qr,hr,ar,br,kr,rr;
int ir=0,jr=0,indexr=1,pr,sizer;
bool flagr=true,flr=false;
cin>>ar>>br>>kr>>pr;
qr=ar;
while(1)
{hr=qr*10;
rr=ar*pow(jr+1);
if(rr%br==0) {fill_0(indexr);ltoa(rr/br,xr,10);cr+=xr;flr=true;break;}
if(rr>br && flagr) {indexr=jr;flagr=false;}
ir=hr/br;
tr+=char(ir+48);
if((jr+1)%2==0)
{cr=tr.substr(0,(jr+1)/2);dr=tr.substr((jr+1)/2);
if(cr==dr && !only_0()) break;
}
qr=hr%br;
jr++;
}
sizer=cr.size();
if(!flr) {
ir=kr%sizer-1;jr=0;
if(ir<0) ir=0;
while(jr<pr)
{if(ir>=sizer) ir=0;
cout<<cr[ir];
ir++;jr++;
}}
else {
if(kr>sizer)
for(jr=0;jr<pr;jr++)
cout<<0;
else {
jr=kr-1;
while(jr<sizer && pr>0)
{cout<<cr[jr];jr++;pr--;}
if(pr>0)
while(pr>0) {cout<<0;pr--;}
}}
cout<<endl;	
return 0;
}