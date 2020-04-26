#include <bits/stdc++.h>
using namespace std;
#define int long long

int p = (int)1e9 + 7;
// fact mod p ( fixed broken version )
int fact(int n) 
{ 
    if(n == 0 || n == 1)
      return 1;
    int f = 1;
    for(int i = 2; i <= n; i++) {
      f = ((f % p )* (i % p)) % p;
    }
    return f % p;
} 

// calculate the a ** n mod p
int binary_exponentiation(int x, int n) {
  if(n == 0)
    return 1; 
  else if(n == 1)
    return x % p;
  else {
    int temp = binary_exponentiation(x, n/2);
    temp = (temp * temp) % p;
    if (n % 2)
      return ((x % p) * temp)%p;
    else
      return temp;
  }
}
void solve(int n, int m) {  
  int num = fact(n+m-1);  
  int den1 = fact(n);  
  int den2 = fact(m-1);
   
  int temp = ((den1 % p) * (den2 % p)) % p;
  int mtemp = binary_exponentiation(temp, p-2);  
  int ans = ((num % p) * (mtemp % p)) % p;
  printf("%lld\n", ans);
}

int32_t main() { 
  int t;
  scanf("%lld", &t);
  while(t--) {
    int m,n;
    scanf("%lld %lld", &n, &m);
    solve(n,m);
  }

  return 0;
}
/*** 
// ********** Below code is the test for fact mod p *************
int32_t main() {
  int n = 5;

  printf("%lld", fact(n));

  return 0;

}

// ******* Hell yeah ! Test passed ****************
***/