#include<bits/stdc++.h>
#define MAX 7000
using namespace std;

void solve() {
    char s[MAX];
    scanf("%s", s);
    
    int n = strlen(s);
    vector< vector<int> > dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for(int cl = 2; cl <= n; cl++) {
        for(int i = 0; i < n-cl+1; i++) {
            int j = i + cl - 1;
            if(s[i] == s[j])
                dp[i][j] = dp[i + 1][j-1];
            else
                dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);

        }
    }
    //print the state table to check if it is on point
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            printf("%d ", dp[i][j]);
        }
       printf("\n"); 
    }
    //yup state table in on point
    printf("%d\n", dp[0][n-1]);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
