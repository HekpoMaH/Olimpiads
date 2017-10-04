//e1
#include<iostream>
using namespace std;
int main()
{
  long int n;
  int br=0;//broya na chetnite cifri
  int sum1=0;//sumata na chetnite cifri
  int sum2=0;//sumata na nechetnite cifri
  int max=0;// za namirane na maksimalnata cifra
  int min=9;//za namirane na minimalnata cifra
  int r,c;//r-razlikata na maksimalnata i minimalnata cifra
  
	cin>>n;
	while(n!=0)
{       
   c=n%10;
   if(c%2==0) {
               br++;
               sum1=sum1+c;
               }
	      else {
                sum2=sum2+c;
                }

	if(sum1>=10) {sum1=sum1/10+sum1%10;}
	if(sum2>=10) {sum2=sum2/10+sum2%10;}
	if(c>max){ max=c;}
	if(c<min) {min=c;}
	n=n/10;
}
r=max-min;
cout<<br<<sum1<<sum2<<r<<endl;
system("pause");
return 0;
}
