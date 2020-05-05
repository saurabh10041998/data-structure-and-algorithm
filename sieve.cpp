#include<bits/stdc++.h>
using namespace std;

const int size = (int)1e5 + 5;
int P[size];
// sieve of erathonas O(nloglogn) implementation...

void generateSieve(int n) {
	
	//all odd can be candidate to sieve
	for(int i = 3; i <=n; i+=2)
		P[i] = 1;
	//sieve  algo 
	for(int i=3; i<= n; i+=2) {
		if(P[i]){
			for(int j = i * i; j <= n; j+=i)
				P[j] = 0;
		}
	}
	//handle edge cases
	P[0] = 0;
	P[1] = 0;
	P[2] = 1;

}

void printSieve(int n) {
	for(int i = 2; i <= n; i++){
		if(P[i])
			printf("%d ", i);
	}
	printf("\n");
}
int main() {
	// get the value of the n and pass to generate sieve..
	int n;
	scanf("%d", &n);
	generateSieve(n);
	printSieve(n);
	return 0;
	
}
