#include<bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define lsh(i) (1 << (i))
#define rep(i, l, r) for(int i = (l); i<(r); ++i)
#define per(i, l, r) for(int i = (l); i >= (r); --i)
#define SPEED ios::sync_with_stdio(false); cin.tie(0)
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int > 
#define pb push_back
#define SIZE (int)(2e6)+ 69
#define __init__(t) int t; cin>>t; while(t-- > 0)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
//mt19937 rnd(time(NULL));

struct obj{
  int id;
  int p, w;
};

typedef struct obj obj;

void operator<<(ostream &out, obj &a){
  out<<a.id<<" "<<a.p<<" "<<a.w<<" "<<(double)a.p/a.w <<endl;
}

//comparator to sort them according to p/w>>
bool operator<(obj a, obj b){
  return ((double)a.p/a.w  > (double)b.p/b.w);
}
// 0 and 1 knapsack problem;

void solve(){
  int m,n;
  cin>>m>>n;

  vector< obj > T(n);
  rep(i, 0, n){
    cin>>T[i].p>>T[i].w;
    T[i].id = i + 1;
  }

  sort(T.begin(), T.end());

  vector<int>list; //list of objects in knapsack;
  double profit = 0;
  int i;
  for(i = 0; i < T.size(); ++i){
    if(m > 0 && T[i].w <= m){
      m = m - T[i].w;
      profit = profit + (double)T[i].p;
      list.pb(T[i].id);
    }else{
      break;
    }
  }

  bool is_fraction = false;
  if(m > 0) {
    //fractional profit
    profit = profit +(double) T[i].p *(double) m / T[i].w;
    list.pb(T[i].id);
    is_fraction = true;
  }
  cout<<profit<<endl;

  cout<<"knapsack = [ ";
  rep(i, 0, list.size() - 1)
    cout<<list[i]<<",";
  cout<<list[list.size() - 1];
  if(is_fraction)
    cout<<" (F)";
  cout<<" ]";
}

int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  SPEED;
      	
    solve();    		
  return 0;			
}