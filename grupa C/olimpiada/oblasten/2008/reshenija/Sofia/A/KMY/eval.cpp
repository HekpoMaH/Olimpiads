#include<cstdio>
#include<cstring>

char niz[32];
int l;

char obr[32],obr_l;

char op_st[32],top;

int vars=1;

int pri(char a) {
	if(a=='+'||a=='-') return 2;
	if(a=='*'||a=='/') return 3;
	if(a=='^') return 1;
}

int cpr;
int main() {
	scanf("%s",niz);
	l=strlen(niz);
	
	for(int i=0;i<l;++i) {
		if(niz[i]=='(') cpr+=5;
		if(niz[i]==')'){if(top>0)obr[obr_l++]=op_st[--top];cpr-=5;}
		if(niz[i]>='a'&&niz[i]<='z') {obr[obr_l++]=niz[i];}
		if(niz[i]=='+'||niz[i]=='-'||niz[i]=='*'||niz[i]=='/'||niz[i]=='^') {
			if(top>0&&(cpr+pri(op_st[top-1]))<=pri(niz[i])) {
				obr[obr_l++]=op_st[top-1];
				op_st[top-1]=niz[i];
			} else {
				op_st[top++]=niz[i];
			}
		}
	}
	
	while(top>0) obr[obr_l++]=op_st[--top];
//	printf("%s\n",obr);		
	
	int p1,p2;
	int j;
	for(int i=0;i<obr_l;++i) {
		if(obr[i]=='+'||obr[i]=='*') {
			for(j=i-1;obr[j]==-1;--j);
			p1=j;
			for(j=j-1;obr[j]==-1;--j);
			p2=j;
			if((obr[p1]=='+'||obr[p1]=='-'||obr[p1]=='*'||obr[p1]=='/'||obr[p1]=='^')&&
				(obr[p2]=='+'||obr[p2]=='-'||obr[p2]=='*'||obr[p2]=='/'||obr[p2]=='^'))
				vars*=2;
			else {
				if(obr[p1]=='-'&&obr[i]=='+') vars*=2;
				if(obr[p1]=='/'&&obr[i]=='*') vars*=2;
			}
			
			obr[p1]=-1;
			obr[p2]=-1;
		}
		if(obr[i]=='-') {
			for(j=i-1;obr[j]==-1;--j);
			p1=j;
			for(j=j-1;obr[j]==-1;--j);
			p2=j;
			//printf("+%d %d",p1,p2);
			if(obr[p2]=='+') vars*=2;
			obr[p1]=-1;
			obr[p2]=-1;
		}
		if(obr[i]=='/') {
			for(j=i-1;obr[j]==-1;--j);
			p1=j;
			for(j=j-1;obr[j]==-1;--j);
			p2=j;
			//printf("+%d %d",p1,p2);
			if(obr[p2]=='*') vars*=2;
			obr[p1]=-1;
			obr[p2]=-1;
		}
	}
	printf("%d\n",vars);
	return 0;
}
