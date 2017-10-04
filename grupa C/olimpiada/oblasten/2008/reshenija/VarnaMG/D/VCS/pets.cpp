#include<iostream>
using namespace std;
int main(){
		string a[5];
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
			int br_cat=0,br_gpi=0;
			for(int j=0;j<a[i].size();j++){
				if(a[i][j]=='C' || a[i][j]=='A' || a[i][j]=='T') br_cat++;
				if(a[i][j]=='G' || a[i][j]=='P' || a[i][j]=='I') br_gpi++;
				}
			if(br_cat>0 || br_gpi>0){
				if(br_cat > br_gpi) cout<<"CAT\n";
				else if(br_cat < br_gpi) cout<<"GPI\n";
				else cout<<"CAT-GPI\n";
				}
			else cout<<"UFO\n";
			}
		//system("pause");
		return 0;
}
