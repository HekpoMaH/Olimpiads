#include <cstdio>
#include <deque>

using namespace std;

const int MAXN=1<<9;

int n, p;
double a[MAXN], sums[MAXN], s0[MAXN];
double ans=0;
deque<int> gr[MAXN];
deque<int> gr0[MAXN];

void init (void) {
     scanf("%d%d", &n, &p);
     for (int i=0; i<n; ++i) scanf("%lf", &a[i]);
     
     for (int i=0; i<=n-p; ++i) { gr[0].push_back(i); gr0[0].push_back(i); sums[0]+=a[i]; s0[0]+=a[i]; }
     for (int i=1; i<=p; ++i) { gr[i].push_back(n-p+i); gr0[i].push_back(n-p+i); s0[i]=sums[i]=a[n-p+i]; }
}

double count_di (int i) {
       double mid=sums[i]/gr[i].size();
       
       double di=0;
       for (int k=0; k<gr[i].size(); ++k)
           di+= (mid-a[gr[i][k]])*(mid-a[gr[i][k]]);
       
       return di;
}

void tr (int i) {
     double D=0;
     for (int i=0; i<p; ++i) D+=count_di(i);
     ans<?=D;
     
     while (true) {
           int tmp=*(gr[i].end()-1);
           gr[i].pop_back();
           if (!gr[i].size()) break;
           
           //for (int i=0; i<p; ++i) printf("%lf ", sums[i]);
           //printf("\n");
           
           sums[i]-=a[tmp];
           gr[i+1].push_front(tmp);
           sums[i+1]+=a[tmp];
           
           tr(i+1);
           }
     /*
     D=0;
     for (int i=0; i<p; ++i) D+=count_di(i);
     ans<?=D;
     */
     }

void solve (void) {
     /*
     vector<int>::iterator it;
     for (it=gr[0].begin(); it!=gr[0].end(); ++it) printf("%lf ", a[*it]);
     printf("\n");
     for (int i=1; i<p; ++i) printf("%lf\n", a[gr[i][0]]);
     for (int i=0; i<p; ++i) printf("%lf ", sums[i]);
     */
     
     for (int i=0; i<p; ++i) ans+=count_di(i);
     
     while (true) {
           int tmp=*(gr[0].end()-1);
           gr[0].pop_back();
           if (!gr[0].size()) break;
           
           sums[0]-=a[tmp];
           gr0[1].push_front(tmp);
           s0[1]+=a[tmp];
           for (int k=1; k<p; ++k) {
               gr[k]=gr0[k];
               sums[k]=s0[k];
               }
           
           tr(1);
           }
     
     printf("%.4lf\n", ans*2);
}

int main()
{
    init();
    solve();
    
    return 0;
}
