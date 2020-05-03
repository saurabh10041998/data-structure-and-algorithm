#include<bits/stdc++.h>
using namespace std;
//reference : google cp-algorithms home page
//way1 : recursive way for extended euclid algorithm
int _gcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = _gcd(b, a % b, x1, y1);
	// update the x and y...
	x = y1;
	y = x1 - y1 * (a / b);
	// return the gcd recieved from bottom..
	return d;
}

//way2 : iterative way for extended algorithm...
int gcd(int a,int b, int &x, int &y) {
	// x1 and y1 just complement in assignment of x and y
	int a1 = a, b1 = b, x1 = 0, y1 = 1;
	x = 1, y = 0; //initial value..
	while(b1) {
		int q = a1 / b1; 
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1)= make_tuple(b1, a1 - q * b1); // this is same as euclid ones
	}
	return a1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a < b) {
			tie(a,b) = make_tuple(b,a); 
		}
		// we call the function to get the gcd and x, y
		int x, y;
		int ans = gcd(a, b, x, y);
		printf("(x, y, gcd ) = (%d,  %d,  %d )\n", x, y, ans);
	}
	return 0;

}