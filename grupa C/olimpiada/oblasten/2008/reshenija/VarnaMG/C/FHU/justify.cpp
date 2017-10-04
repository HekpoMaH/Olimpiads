#include<iostream>
using namespace std;
int main(){
char s[63];
int i,brdum=0,j,ost,ex;
unsigned long long n,p;
cin>>n;
cin.getline(s,62);
for(p=1;p<=n;p++){
	//getch();
	brdum=0;
	cin.getline(s,62);
	//cout<<s<<endl<<endl;
	for(i=0;i<strlen(s);i++)
	if(s[i]!=' ')break;
	strcpy(s,s+i);
	for(i=strlen(s)-1;i>=0;i--)
	if(s[i]!=' ')break;
	s[i+1]='\0';
	for(i=0;i<strlen(s);i++)
	if(s[i]==' '){
		          brdum++;
		          for(j=i+1;j<strlen(s);j++)
		           if(s[j]!=' ')break;
		          if(j!=strlen(s)) 
		           strcpy(s+i,s+j-1);
				}
	if(brdum){
	ex=(60-strlen(s))/brdum+1;
	ost=(60-strlen(s))%brdum;}
	if(p!=n){
	for(i=0;i<=strlen(s);i++)
	  if(s[i]!=' ')cout<<s[i];
	  else {
			for(j=1;j<=ex;j++)
			  cout<<' ';
			if(ost){
				cout<<' ';
				ost--;
		    	}
		  }  
		  }
	else cout<<s;	  			
	cout<<endl;
	//cout<<ex<<' '<<brdum<<' '<<strlen(s)<<endl;
}
	return 0;
}
