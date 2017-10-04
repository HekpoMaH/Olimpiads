#include<iostream>
using namespace std;
int main() {
    bool stanalitovacisalo[100],otkrixmecifri;
    long long yravania=0,kolkocisla,br,brzacifri,cisla[100],polycenocislo[100],cifri[100],otkrivanenacifri[100],cifrinapolycenocislo[100],copynapolycenocislo[100];
    cin>>kolkocisla;
    for (br=0;br<kolkocisla;br++) {
        cin>>cisla[br];
        if (cisla[br]>3) {
            otkrivanenacifri[br]=cisla[br];
            for (brzacifri=0,otkrixmecifri=false;(brzacifri<100)&&(otkrivanenacifri[br]>0)&&(!otkrixmecifri);brzacifri++) {
                if (otkrivanenacifri[br]<=9) {
                    cifri[br]=brzacifri+1;
                    otkrixmecifri=true;
                }
                otkrivanenacifri[br]=otkrivanenacifri[br]/10;
            }

            polycenocislo[br]=cisla[br]*cisla[br];
            copynapolycenocislo[br]=polycenocislo[br];

            for (brzacifri=0,otkrixmecifri=false;(brzacifri<100)&&(copynapolycenocislo[br]>0)&&(!otkrixmecifri);brzacifri++) {
                if (copynapolycenocislo[br]<=9) {
                    cifrinapolycenocislo[br]=brzacifri+1;
                    otkrixmecifri=true;
                }
                copynapolycenocislo[br]=copynapolycenocislo[br]/10;
            }

            polycenocislo[br]=(polycenocislo[br]-((polycenocislo[br]/(10*cifri[br]))*10*cifri[br]))+polycenocislo[br]/(10*(cifrinapolycenocislo[br]-cifri[br]));
            if (polycenocislo[br]==cisla[br]) {
                yravania++;
            }
        }
    }

    cout<<endl;
    return 0;
}
