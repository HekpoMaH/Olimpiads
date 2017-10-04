#include <iostream>
using namespace std;

long long pow(long long num,long long up){
    long long sum = 1;
    for(long long i = 0; i < up; i ++){
        sum = sum * num;
    }
    return sum;
}

long long digits(long long num){
    long long dig = 0;
    long long copyNum = num;
    for( ; copyNum != 0 ; ){
        copyNum = copyNum / 10;
        dig ++;
    }
    return dig;
}

int main(){
    long long times = 0;
    long long lenght;
    long long elementLenght[100];
    long long nums[100];
    cin >> lenght;
    for(long long count = 0; count < lenght; count ++){
        long long first;
        long long second;
        cin >> nums[count];
        first = (nums[count] * nums[count]) % pow(10, digits(nums[count]));
        second = (nums[count] * nums[count]) / pow(10, digits(nums[count]));
        if(first + second == nums[count]) times ++;
    }
    cout << times << endl;
    return 0;
}
