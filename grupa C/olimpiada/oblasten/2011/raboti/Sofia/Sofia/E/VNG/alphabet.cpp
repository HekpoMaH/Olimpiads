#include<iostream>
using namespace std;
int main() {
    char imenanafilmi[20][80],koiaebykvata[2];
    bool specelili,vivedoxmelifilma;
    long long br,koiabykva,kolkofilma,brzavav;
    cin>>koiabykva>>kolkofilma;
    koiaebykvata[0]=koiabykva+'a'-1;
    koiaebykvata[1]=koiabykva+'A'-1;
    for (br=0;br<kolkofilma;br++) {
        for (brzavav=0,vivedoxmelifilma=false;(brzavav<80)&&(!vivedoxmelifilma);brzavav++) {
            cin>>imenanafilmi[br][brzavav];
            if (imenanafilmi[br][brzavav]=='.') {
                vivedoxmelifilma=true;
            }
        }
    }


    for (br=0,specelili=false;(br<kolkofilma)&&(!specelili);br++) {
        if ((imenanafilmi[br][0]==koiaebykvata[0])||(imenanafilmi[br][0]==koiaebykvata[1])) {
            specelili=true;
        }
    }


    if (specelili) {
        cout<<"win "<<br;
    } else {
        cout<<"lose";
    }
    cout<<endl;

    return 0;
}
