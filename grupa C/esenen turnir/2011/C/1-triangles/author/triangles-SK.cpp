//Task: triangles
//Author: Stoyan Kapralov

#include <iostream>
using namespace std;

bool colinear(int x0, int y0, int x1, int y1, int x2, int y2)
{ int a1=x1-x0, a2=y1-y0;
	int b1=x2-x0, b2=y2-y0;
  return  a1*b2==a2*b1;
}

int main()
{
	char name[26];
  int x[26], y[26];

	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> name[i] >> x[i] >> y[i];

  bool found = false;
	for(int i=0;i<n;i++)
	  for(int j=i+1; j<n; j++)
      for(int k=j+1; k<n; k++)
        if(!colinear(x[i],y[i],x[j],y[j],x[k],y[k]))
        { cout <<name[i]<<" "<< name[j]<<" "<< name[k]<<endl;
          found = true;
				}

    if(!found) cout << "No triangles." << endl;
    return 0;
}
