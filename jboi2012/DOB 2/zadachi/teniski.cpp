#include <iostream>
using namespace std;
int main()
{
	int a,b,x,y,brh,brv,sh,sv;
	cin>>a>>b>>x>>y;
	brh=(a/x)*(b/y);
	sh=a*b-brh*(x*y);
	brv=(a/y)*(b/x);
	sv=a*b-brv*(x*y);
	if(brv>brh) cout<<brv<<endl<<sv<<endl;
    	else cout<<brh<<endl<<sh<<endl;
    	system ("pause");
	return 0;
}
