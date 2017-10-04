//Iordan Boev SMG
# include <stdio.h>
# define MAXN (1<<16)

int pro[MAXN];
int n;
int data[MAXN];
int primes[MAXN],br;
int ch;

void read() {
	scanf("%d", &n);	
}

void work() {
	pro[0]=1;
	pro[1] = 1;
	for(int i = 2; i < 50030; i++) {
		if(pro[i] == 0) {
			primes[br++] = i;
			for( int j = i+i; j <= 55000; j+=i ) {
				pro[j] = 1;	
			}	
		}	
	}
	for(int i = n+1; ; i++) if(pro[i] == 0) {ch = i; break;}
}

void solve() {
	data[1] = 0;
	data[2] = 1;
	data[3] = 1;
	data[4] = 1;
	data[5] = 2;
	data[6] = 2;
	data[7] = 3;
	data[8] = 3;
	for(int i = 9; i <= n; i++) {
		if(pro[i] == 0) data[i]++;
		for(int j = 0; primes[j] < i; j++) {
			//if(i==11)printf("%d   ", primes[j]);
			//if(primes[j] == i-primes[j] && pro[primes[j]] == 0) data[i]++;
			if(pro[i-primes[j]] == 0 && i-primes[j] < primes[j]) continue;
			data[i] += data[i-primes[j]]%ch;
			//if(i==11)printf("%d   ", data[i]);	
			for(int k = j-1; k >= 0; k--) {
				int p = i-(primes[j]+primes[k]);
				
				if(p>0) {
					data[i] -= data[p];	
					if(pro[p] == 0 && p < primes[k]) data[i] += data[i-(primes[j]+p)];
				}
			}
			data[i]= (data[i]+ch)%ch;
			//if(i==11)printf("%d\n", data[i]);	
			
		}		
	}
	if(pro[n] == 0) data[n]--;
	//printf("ans = %d  ", data[9]);
	if(data[n] > 0) printf("%d\n", data[n]%ch);	
}

int main() {
	read();		
	work();	
	solve();
	return 0;
}
