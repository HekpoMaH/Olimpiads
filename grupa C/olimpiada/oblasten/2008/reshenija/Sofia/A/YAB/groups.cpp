//Iordan Boev SMG
# include <stdio.h>
# define MAXN (1<<9)
# define min(a,b) ((a) > (b) ? (b) : (a))
# define dmax (912354451.0)

int n,p;
double data[MAXN][MAXN];
double prev[MAXN];
double a[MAXN];

void read() {
     scanf("%d %d", &n,&p);
     prev[0] = 0.0;
     for(int i = 1; i <= n; i++) {
     	scanf("%lf", &a[i]);               
		prev[i] = prev[i-1]+a[i];
     }     
}

double d(int p,int q) {
	double si = (prev[q] - prev[p-1])/(q-p+1);
	double ans=0.0;
	for(int i = p; i <= q; i++)	{
		ans+= (a[i]-si)*(a[i]-si);	
	}
	return ans;	
}

void solve() {
	for(int i = 1; i <= n; i++) {
		data[i][i] = 0;
		for(int j = 1; j <= i; j++) {
			data[i][1] = d(1,i);	
		}	
	}
	for(int i = 3; i <= n; i++) {
		for(int j = 2; j < i; j++) {
			//smqtame data[i][j]
			data[i][j] = dmax;
			for(int k = 1; k < i && i-k>=j-1; k++) {
				data[i][j] = min( data[i][j], (data[i-k][j-1]+d(i-k+1,i)) );	
			}	
		} 	
	}	
/*	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%3.3lf ", data[i][j]);  	
		}
		printf("\n");	
	}*/
	printf("%.4lf\n", data[n][p]);
}

int main() {
    read();
	solve();   
    
    return 0;
}
