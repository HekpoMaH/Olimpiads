#include<iostream>
using namespace std;

const int n_max=50005;
int n;
int a[n_max], b[n_max], c[n_max];

int merge(int a[],int beg, int mid, int end)
{
int v=0;
int n = end - beg + 1;
int b[n];
int i1 = beg;
int i2 = mid + 1;
int j = 0;
while ((i1 <= mid) && (i2 <= end))
{ if (a[i1] < a[i2]) {b[j]=a[i1]; i1++;}
else {b[j]=a[i2]; i2++; v += (mid-i1+1);}
j++;
}
while(i1 <= mid) {b[j]=a[i1]; i1++; j++;}
while(i2 <= end) {b[j]=a[i2]; i2++; j++;}
for(j=0; j<n; j++) a[beg+j] = b[j];

return v;
}

int merge_sort(int a[],int beg, int end)
{
if (beg == end) return 0;
int mid = (beg + end) / 2;
int v=0;
v += merge_sort(a, beg, mid);
v += merge_sort(a, mid + 1, end);
v += merge(a, beg, mid, end);
return v;
}

int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];

  for(int i=0;i<n;i++) c[a[i]]=i+1;
  for(int i=1;i<=n;i++)cout<<c[i]<<" ";
  cout<<endl;
  for(int i=0;i<n;i++) b[i]=c[b[i]];

  int vb=merge_sort(b,0,n-1);

  cout << vb << endl;
}


