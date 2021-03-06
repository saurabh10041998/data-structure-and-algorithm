#include<bits/stdc++.h>
#define endl "\n"
using namespace std; 


struct segtree {

        int size;
        vector<long long>sums;

        void init(int n) {
            //nearest power of 2
            size = 1;
            while(size < n) size *= 2;
            sums.assign(2 * size, 0LL);
        }

        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }

        //segment tree call
        void set(int i, int v, int x, int lx, int rx) {
            if(rx - lx == 1) {
                sums[x] = v;
                return;
            }

            int m = (lx + rx)/2;
            if(i < m) {
                set(i, v, 2 * x + 1, lx, m);
            }else {
                set(i, v, 2 * x + 2, m, rx);
            }

            //recalculate the sums this is important..
            sums[x] = sums[2 * x + 1] + sums[2 * x + 2]; 
        }

        long long sum(int l, int r) {
            return sum(l, r, 0, 0, size);
        }

        //segment tree call
        long long sum(int l, int r, int x, int lx, int rx) {
            //No overlap    
            if(lx  >= r || rx <= l) return 0;
            //complete overlap
            if(lx >= l  && rx <= r) return sums[x];
            
            //partial overlap.. 
            int m  = (lx + rx) /2;
            long long s1 = sum(l, r, 2 * x + 1, lx, m);
            long long s2 = sum(l, r, 2 * x + 2, m, rx);
            return s1 + s2; 
        }

        void build(vector<long long>& a) {
            
           build(a, 0, 0, size); 
        
        }
    
        //segment tree call
        void build(vector<long long>& a, int x, int lx, int rx) {
                if(rx - lx == 1) {
                    if(lx < (int)a.size())
                       sums[x] = a[lx];
                  return;  
                }
                int m = (lx + rx)/ 2;
                
                build(a, 2 * x  + 1, lx, m);
                build(a, 2 * x + 2, m, rx);
                sums[x] = sums[2 * x + 1] + sums[2 * x  + 2];        
        }       

}; 

int main()  {


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    segtree st; 

    //We are writing build bois
    vector<long long>a(n);
    st.init(n);

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
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
            long long ans = st.sum(l, r);
            cout<<ans<<endl;        
        }
    
    }
    
    return 0;
    
}
