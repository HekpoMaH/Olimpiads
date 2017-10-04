#include<cstdio>
#include<cstdlib>
#include<ctime>

double a[1024];
int n,p;

double best_d;

double sums[1024];

time_t ttt;

//double memo[1024][1024];
void suicide() {
	printf("%lf\n",best_d);
	exit(0);
}

double calc(int beg,int end) {
	if(end>n) return 600000000.0;
	
//	if(memo[beg][end]!=0) return memo[beg][end];
//	printf("calc %d %d\n",beg,end);
	
	
	double newd=0;
	double s=(sums[end]-sums[beg-1])/double(end-beg+1);
//	printf("s=%lf %lf %lf\n",s,sums[end]-sums[beg-1],double(end-beg+1));
	for(int i=beg;i<=end;++i) {
		newd+=(s-a[i])*(s-a[i]);
	}
//	memo[beg][end]=newd;
	return newd;
}

void rec(int num,int rem_gr,int max_size,double d) {
	if(clock()-ttt>1000) suicide();
//	printf("found d=%lf %d %d\n",d,num,max_size);
	if(num>n+1) return;
	if(num==n+1) {if(d<best_d) best_d=d;}
	if(rem_gr<1) return;
	
	for(int i=max_size;i>0;--i) {
		rec(num+i,rem_gr-1,i,d+calc(num,num+i-1));
	}	
}

int main() {
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;++i) scanf("%lf",&a[i]);
	
	best_d=600000000;
	
	sums[1]=a[1];
	for(int i=2;i<=n;++i) sums[i]=a[i]+sums[i-1];
	
//	for(int i=1;i<=n;++i) printf("%lf ",sums[i]);
//		printf("\n");
	
//	printf("%lf",calc(1,4));
	//calculate 
	
//	printf("\n%d %d %d %lf\n\n",n,p,n-p+1,calc(1,6));
	ttt=clock();
	
	rec(1,p,1,0);
	rec(1,p,2,0);
	rec(1,p,3,0);
	rec(1,p,n-p+1,0);
	
	printf("%lf\n",best_d);
	return 0;	
}
