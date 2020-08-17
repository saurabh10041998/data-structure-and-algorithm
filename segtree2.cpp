//Segtree for function calc ==> mincount() 
//Number of element equal to minimum of segments

#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;


struct item {
    int m, c;
};

struct segtree {
    int size;
    vector<item>values;
    item NEUTRAL_VALUE = {INT_MAX, 1};

    item single(int c) {
        return {c, 1}; 
    }

    item merge(item a, item b) {
        if(a.m  < b.m)
            return a;
        if(b.m < a.m)
            return b;
        return { a.m , a.c  + b.c }; 
    }

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        values.resize(2 * size);
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                values[x] = single(a[lx]);                
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x  + 1], values[2 * x + 2]); 
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;

        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]); 
    }

    // @mincount
    
    item calc(int l, int r)  {
        return mincount(l, r, 0, 0, size);
    }

    item mincount(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l)  return NEUTRAL_VALUE;
        if(lx >= l && rx <= r) return values[x];
        
        int  m = (lx + rx) /2;
        item s1 = mincount(l, r, 2 * x + 1, lx, m);
        item s2 = mincount(l, r, 2 * x + 2, m, rx);

        return merge(s1, s2);
    }

    

};

int32_t main() {
    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    for(int i = 0 ; i < n; i++) {
        cin>>a[i];
    }

    segtree st;
    st.init(n);
    
    st.build(a);

    while(m--) {
        int op;
        cin>>op;
        if(op == 1) {
            int i, v;
            cin>>i>>v;
            st.set(i, v);
        }else {
            int l, r;
            cin>>l>>r;
            item mincount = st.calc(l,r);
            cout<<mincount.m<<" "<<mincount.c<<endl;
        }
    }
    return 0;
}
