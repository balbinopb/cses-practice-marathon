#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
#define pb push_back
#define pf push_front
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define DIGITS(x) ((int)to_string(x).size())

vl a, st, lazy;

ll merge(ll left, ll right){
    return left + right;
}

void push(int p, int l, int r){
    if(lazy[p] != 0){
        if(l == r){ 
            st[p] += lazy[p];
        } else {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void build(int p, int l, int r){
    if(l == r){
        st[p] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    st[p] = merge(st[2*p], st[2*p+1]);
}

void update(int p, int l, int r, int L, int R, ll val){
    push(p,l,r);
    if(r < L || R < l) return; // outside
    if(L <= l && r <= R){      // fully inside
        lazy[p] += val;
        push(p,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(2*p, l, mid, L, R, val);
    update(2*p+1, mid+1, r, L, R, val);
}

ll query(int p, int l, int r, int idx){
    push(p,l,r);
    if(l == r) return st[p]; // leaf
    int mid = (l+r)/2;
    if(idx <= mid) return query(2*p, l, mid, idx);
    else return query(2*p+1, mid+1, r, idx);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    a.resize(n+1);
    st.resize(4*n);
    lazy.resize(4*n,0);
    for(int i=1;i<=n;i++) cin >> a[i];

    build(1,1,n);

    while(q--){
        int t; cin >> t;
        if(t == 1){ 
            int l,r; ll val; 
            cin >> l >> r >> val;
            update(1,1,n,l,r,val);
        } else { 
            int idx;
            cin >> idx;
            cout << query(1,1,n,idx) << "\n";
        }
    }
}
