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
#define sii stack < pair<int, int> > 
//mt19937 rnd(time(NULL));

/**
 * Modified queue to solve the problem 
 * finding the minimum of sub_array of fixed length k
* */

void remove_element(sii &x, sii &y){
  //x = rear view
  //y = front view 
  if(y.empty()){
    while(!x.empty()){
      int new_ele = x.top().first;
      x.pop();
      //modified push into y
      int new_min = y.empty() ? new_ele : min(new_ele, y.top().second);
      y.push({new_ele, new_min});
    }
    
  }
  y.pop();
}

void add_element(sii &s, int x){
  // add element and update the min of stack
  int new_min = s.empty()? x: min(x, s.top().second);
  s.push({x, new_min}); 
}

int minimum(sii &x, sii &y){
  if(x.empty() || y.empty()){
    int m = x.empty() ? y.top().second : x.top().second;
    return m;
  }
  return min(x.top().second, y.top().second);
}

vector<int> find_min(vector<int> &x, int n, int k){
  ///modified stacks
  sii s1, s2;
  vector<int> min_ans;
  //insert first k element
  rep(i, 0, k)
    add_element(s1, x[i]);
  min_ans.push_back(minimum(s1, s2));
  rep(i, k, n){
    //remove first element;
    remove_element(s1,s2);
    add_element(s1, x[i]);
    min_ans.push_back(minimum(s1, s2));
  }  
  return min_ans;
}

void solve(){
  int n, k;
  cin>>n>>k;
  vector<int>x(n);
  rep(i, 0, n)
    cin>>x[i];

  vi ans = find_min(x, n, k);
  
  rep(i,0,n)
    cout<<x[i]<<" ";
  
  cout<<endl;

  rep(i, 0, ans.size())
    cout<<ans[i]<<" ";
  
  cout<<endl;
  
}


int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  SPEED; 
  __init__(t)     	
  solve();    		
  return 0;			
}