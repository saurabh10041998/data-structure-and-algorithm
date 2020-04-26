#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vvi vector< vector<int> >
int p = (int)1e9;

int K = 0;

//matrix multiplication
vvi matmul(vvi a, vvi b) {
  vvi c(K+1, vector<int>(K+1));
  for(int i = 1; i <= K; i++) {
    for(int j = 1; j <= K; j++) {
      for(int k = 1; k <= K; k++) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
      }
    }
  }
  return c;
}

//binary exponentiation
vvi binaryExp(vvi x, int n) {
  if(n == 1)
    return x;
  if(n % 2){
    return matmul(x, binaryExp(x, n-1));
  }
  vvi temp = binaryExp(x, n/2);
  return matmul(temp, temp);
}




int32_t main() {

  int t;
  scanf("%lld", &t);

  while(t--) {
    scanf("%lld", &K);
    vector<int>b(K+1);
    for(int i = 1; i<=K; i++) 
      scanf("%lld", &b[i]);
    vector<int>c(K+1);
    for(int i = 1; i<=K; i++) 
      scanf("%lld", &c[i]);
    //creating T
    vvi T(K+1, vector<int>(K+1));
    for(int i=1; i < K; i++)
      T[i][i+1] = 1;
    for(int i=1; i<=K; i++)
      T[K][i] = c[K-i + 1];

    int N;
    scanf("%lld", &N);
    if(N == 1) {
      printf("%lld", b[1]);
    }
    else{
      T = binaryExp(T, N-1);

      int res = 0;
      for(int i=1; i <= K; i++) {
        res = (res + T[1][i] * b[i]) % p;
      }
      printf("%lld\n", res);  

    }   
        
  }
  return 0;

}
