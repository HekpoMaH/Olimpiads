#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{int N,i;
 int S=0;
 int a[7];
 int min=20;
 cin>>N; 
 for(i=0;i<N;i++)
 {cin>>a[i];
 if(a[i]<min)
         min=a[i];
  S=S+a[i];
}
cout<<S-min+1<<endl;

    //system("PAUSE");
    return 0;
}

