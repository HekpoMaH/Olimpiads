#include<iostream>
#include<cmath>
using namespace std;

int broi_deliteli(int n){
	int k=1;
	for(int i=2;i*i<=n;i++){
		if(n%(i*i)==0) k=i; 
		}
		return k;
	}

int main(){
		long a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==0 && b==0 && c==0 && d==0){a=-1000; b=-1000; c=a*a*b; d=a*b*b;}
		if(a==0 && b!=0 && c!=0 && d!=0) a=(d/b)/b;
		if(a!=0 && b==0 && c!=0 && d!=0) b=(c/a)/a;
		if(a!=0 && b!=0 && c==0 && d!=0) c=a*a*b;
		if(a!=0 && b!=0 && c!=0 && d==0) d=a*b*b;
		if(a!=0 && b==0 && c==0 && d==0){b=-1000; c=a*a*b; d=a*b*b;}
		if(a==0 && b!=0 && c==0 && d==0){a=b; c=a*a*b; d=a*b*b;}
		if(a!=0 && b!=0 && c==0 && d==0){c=a*a*b; d=a*b*b;}
		if(a!=0 && b==0 && c!=0 && d==0){b=(c/a)/a; d=a*b*b;}
		if(a==0 && b!=0 && c==0 && d!=0){a=(d/b)/b; c=a*a*b;}
		if(a==0 && b!=0 && c!=0 && d==0){
			if(b<=int( sqrt( float(c/b) ) )*(-1)) a=int( sqrt( float(c/b) ) )*(-1);
			else a=int( sqrt( float(c/b) ) );
			d=a*b*b;}
		if(a!=0 && b==0 && c==0 && d!=0){b=int(sqrt(float(d/a)))*(-1); c=a*a*b;}
		if(a==0 && b==0 && c==0 && d!=0){
			if(d<0){b=broi_deliteli(abs(d))*(-1); a=(d/b)/b;}
			else{
				b=broi_deliteli(d)*(-1);
				a=(d/b)/b;
				}
			c=a*a*b;
			}
		if(a==0 && b==0 && c!=0 && d==0){
			if(c<0){a=-1; b=c;}
			else{
				a=broi_deliteli(c);
				b=(c/a)/a;
				}
			d=a*b*b;
			}
		if(a==0 && b==0 && c!=0 && d!=0){
			if(d<0) for(int i=2;i*i<=abs(d);i++) if(d%i==0 && c%(i*i)==0) a=i*(-1);
			else for(int i=2;i*i<=d;i++) if(d%i==0 && c%(i*i)==0) {a=i; break;}
			b=c/(a*a); 
			}
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		//system("pause");
		return 0;
}
