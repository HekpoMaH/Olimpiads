#include<iostream>
using namespace std;
int main()
{
	int GPI=0,CAT=0,l,fl=0,br=0;
	char z;
	cin>>l;
	for (fl=0;fl<l;fl++)
	{
		while (z!='\n')
		{
		    cin.get(z);
			if (z=='G')
				{GPI=GPI+1;}
			if (z=='P')
				{GPI=GPI+1;}
			if (z=='I')
				{GPI=GPI+1;}
			if (z=='C')
				{GPI=GPI+1;}
			if (z=='A')
				{GPI=GPI+1;}
			if (z=='T')
				{GPI=GPI+1;}
			if (CAT>GPI)
				cout<<"CAT"<<endl;
			if (GPI>CAT)
				cout<<"GPI"<<endl;
			if (CAT==GPI)
			     if (CAT>0 && GPI>0)
			    	cout<<"CAT-GPI";
			
			if (CAT==0 && GPI==0)
					cout<<"UFO";
		}
		if (z=='\n');
			{
				CAT=0;
				GPI=0;
			}
	}
	return 0;
}
