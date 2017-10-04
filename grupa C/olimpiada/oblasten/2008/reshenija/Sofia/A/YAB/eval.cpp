//Iordan Boev SMG
# include <stdio.h>

char data[32];

void read() {
	scanf("%s", data);	
}

int solve(int p) {
	int ans=0;
	while(data[p]!='\0') {
		if(data[p] == '(' || data[p] == ')') ans+=2; 
		if(data[p] == '+' || data[p] == '-') ans+=1;
		if(data[p] == '*' || data[p] == '/') ans+=3;	
		p++;
	}
	ans = (ans/2-1)/2;
	if(ans == 0) ans = 1;
	return ans;
}

int main() {
	read();
	printf("%d\n", solve(0));	
	return 0;
}
