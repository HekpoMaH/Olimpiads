/*
dfrac.cpp
Solution by Number Theory - O(b) time
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define num long

long powmod(long a, long k, long b){
	//returns a^k mod b
	long res;
	if(k == 0) return 1;
	if(k % 2 == 0){
		res = powmod(a, k / 2, b);
		res *= res;
		res %= b;
		return res;
	}else{
		res = a * powmod(a, k - 1, b);
		res %= b;
		return res;
	}
}
long gcd(long a, long b){
	if(a == 1 || b == 1) return 1;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a == b) return a;
	if(a > b) return gcd(b, a % b);
	else return gcd(a, b % a);
}

int main(){
	num a, b, bt, phib = 1, currd, msqr, k = 0, tenst, gc;
	int i, p, dig;
	char ch;
	scanf("%ld %ld", &a, &b);
	/*
	1. normalize the fraction - a = a % b a/b <= 1
	*/
	a = a % b;
	gc = gcd(a, b);
	a = a / gc;
	b = b / gc;
	/*
	2. find EulerPhi(b) in O(b) time
	*/
	bt = b;
	/*
	the first divisor of every number is prime
	*/
	currd = 2;
	while(bt > 1){
		msqr = (long)sqrt((double) bt) + 1;
		while(currd <= msqr && bt % currd != 0) currd++;
		if(bt % currd == 0){
			while(bt % currd == 0){
				bt = bt / currd;
				phib *= currd;
			}
			phib /= currd;
			phib *= currd - 1;
			continue;
		}else{
			//bt is prime
			phib *= bt - 1;
			break;
		}
	}
	/*
	now EulerPhi(b) is in phib
	*/
	/*
	3. Translate k:
	a^k = a^(k % Phi(b)) mod b
	*/
	scanf("%c", &ch);	//' ' or '\n'
	scanf("%c", &ch);
	while('0' <= ch && ch <= '9'){
		k = 10 * k + (ch - '0');
		k = k % phib;
		ch = getchar();
	}
	//now ch is ' ' or '\n'
	scanf("%d", &p);
	/*
	k is the first digit to begin
	*/
	/*
	how to find the kth digit of a/b fast?
	(a/b <= 1) a/b = 0.xyzw
	1st digit (x) = 10*a/b
	y = 10*(10*a%b)/b
	3rd = 10*(10^2*a%b)/b
	nth - 10*(10^(n-1)*a%b)/b
	so first we find 10^(k - 1)%b by fast multiplication
	*/
	/*
	handle case k = 0:
	*/
	if(k == 0) k = phib;
	if(b == 1){
		//special case - EulerPhi(1) = 0, but this is easy - no fractional part
		for(i = 0; i < p; i++) printf("0");
		printf("\n");
		return 0;
	}
	tenst = powmod(10, k - 1, b);
	/*
	now we should output the first p digits of tenst/b
	the 1st digit is 10*tenst/b
	the remainder is 10*tenst%b/b
	*/
	for(i = 0; i < p; i++){
		dig = (int)((10*tenst)/b);
		printf("%d", dig);
		tenst = (10*tenst) % b;
	}
	printf("\n");
	//system("pause");
	return 0;
}
