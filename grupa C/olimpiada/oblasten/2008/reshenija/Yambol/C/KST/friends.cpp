#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N,i=1,j=0,pr,max=0,l=0,br=0;
	long M;
	cin>>N>>M;
	long a[10000];
	string c,s[1000],k[1000];
	while (i<=M+1)
	{
		getline(cin,c);
		i++;
		s[i]=c;
	}
	for (i=1;i<=M;i++) {k[i]=s[i].erase(1,2);a[i-1]='k[i]';cout<<a[i]<<" ";}
	i=0;
	j=0;
	while (br<M)
	{   
		pr=0;
		while (a[i]==l) 
	    {
		    pr=pr+1;
	        j++;
	        i++;
        }
        if (pr>max) max=pr;
        l=l+1;
        br=br+j;
    }
    cout<<max;
	return 0;
}
