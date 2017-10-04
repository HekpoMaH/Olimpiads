#include <iostream>

using namespace std;

int main()
{
    int n, m, k, a[100][100];
    int s1=0, s2=0, s3=0, s4=0;
    cin>>n>>m>>k;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin>>a[i][j];
    int ii=(k-1)/m; int jj=k-1-ii*m; 
    for (int i=0; i<ii; i++)
        for (int j=jj+1; j<m; j++) s1+=a[i][j];
    for (int i=0; i<ii; i++)
        for (int j=0; j<jj; j++) s2+=a[i][j];
    for (int i=ii+1; i<n; i++)
        for (int j=0; j<jj; j++) s3+=a[i][j];
    for (int i=ii+1; i<n; i++)
        for (int j=jj+1; j<m; j++) s4+=a[i][j];
     cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;   
        
} 
