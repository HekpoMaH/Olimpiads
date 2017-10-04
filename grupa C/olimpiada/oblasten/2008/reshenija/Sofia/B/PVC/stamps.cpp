#include<iostream>
//#include<iomanip.h
using namespace std;
int main()
{
    int sum,broi,br=0,puti=0,putimin=9999,br2=0,j;
    cin >> sum >> broi;
    if((sum<0)||(sum>5000))return 0;
    if((broi<0)||(broi>3000))return 0;
    int mark[broi-1];
    for(int i=0; i<=broi-1; i++)
    {
            cin >> mark[i];
    }
    sort(mark, mark+broi);
    
    //do tuk e taka
    for(int i=broi-1; i>=0; i--)
    {j=i;//cout << "j=" << j << endl;
            do{
                    if(br+mark[i]<=sum){br+=mark[i];puti++;}
                    else i--;
                    
              }while(br!=sum);
              cout<< puti << endl;
              i=j;//cout << "j=" << j << endl;
              br=0;
            if(puti<putimin)putimin=puti;
            puti =0;
    }
    cout << putimin << endl;
    //system("pause");
    return 0;
}
