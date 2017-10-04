#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int *a;



int main() {
	scanf("%d",&n);

		a=new int[n];
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}

		sort(a,a+n);
		bool ch=false;
		if (a[0]!=a[1]) {
			printf("%d ",a[0]);
			ch=true;
		}
		for (int i=1;i<n-1;i++) {
			if (a[i-1]!=a[i] && a[i]!=a[i+1]) {
				printf("%d",a[i]);
				printf(ch ? "\n" : " ");
			}
		}
		if (a[n-2]!=a[n-1]) printf("%d\n",a[n-1]);


	return 0;
}
