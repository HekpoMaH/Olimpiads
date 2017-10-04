#include <iostream>
#include <string>
#include <algorithm>
const std::string digits="0123456789";
std::string generate(std::size_t a, std::size_t b){
    // can generate 0-9
    // can generate ac - c<b
    // cannot generate ab
    if(b<=a){
        std::string res;
        res=digits.substr(b, a-b+1);
        res+=digits.substr(0, b);
        res+=digits.substr(a+1, 10-a-1);
        return res;
    }else{
        std::string res;
        res=digits[b];
        res+=digits[a];
        res+=digits.substr(0, b);
        res+=digits.substr(b+1, 10-b-1);
        return res;
    }
}
std::string s;
bool mi[2048][2048][2];
std::string minImp(std::size_t digits, std::size_t a, bool notz){
    if(mi[digits][a][notz]) return std::string();
    for(std::size_t i=notz;i<10;i++){
        std::size_t c=std::find(s.begin()+a, s.end(), '0'+i)-s.begin();
        if(c==s.size()) return char('0'+i)+std::string(digits-1, '0');
        if(digits==1) continue;
        std::string a=minImp(digits-1, c+1, false);
        if(!a.empty()) return char('0'+i)+a;
    }
    mi[digits][a][notz]=1;
    return std::string();
}
std::string minImp(){
    for(std::size_t i=1;;i++){
        std::string a=minImp(i, 0, true);
        if(!a.empty()) return a;
    }
}
int main(){
    std::string b, res;
    std::cin>>s;
    b=minImp();
    std::cout<<b<<'\n';
    res+=digits.substr(1, b[0]-'1');
    for(std::size_t i=1;i<b.size();i++) res+=generate(b[i-1]-'0', b[i]-'0');
    while(res[0]=='0') res.erase(res.begin(), res.begin()+1);
    if(b=="1") res="0";
    std::cout<<res<<'\n';
    return 0;
}
