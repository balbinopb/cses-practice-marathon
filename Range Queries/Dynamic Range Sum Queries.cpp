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
 
// const int N = 2e5 + 5;
// ll a[N];
// ll st[4 * N];
 
vl a;
vl st;
 
// in this case how we merge
ll merge(ll left, ll right){
    return (left+right);
 
}
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = a[l];
        return;
    }
 
    int mid = (l + r) / 2;
 
    build(p*2, l, mid);
    build(p*2+1, mid+1, r);
 
    st[p] = merge(st[p*2] , st[p*2+1]);
}
 
void update(int p, int l, int r, int idx, ll val) {
 
    if (l == r) {
        st[p] = val;
        return;
    }
 
    int mid = (l + r) / 2;
 
    if (idx <= mid) {
        update(p*2, l, mid, idx, val);
    }else {
        update(p*2+1, mid+1, r, idx, val);
    }
 
    st[p] = merge(st[p*2] , st[p*2+1]);
}
 
ll query(int p, int l, int r, int L, int R) {
 
    if (R < l || r < L) {
        return 0; // outside range and update this for neutral
    }
 
    if (L <= l && r <= R) {
        return st[p];
    }
 
    int mid = (l + r) / 2;
 
    ll left=query(p*2, l, mid, L, R);
    ll right=query(p*2+1, mid+1, r, L, R);;
 
    return  merge(left,right); 
}
 
 
 
int main() {
    fast_io;
 
    int n, q;
    cin >> n >> q;
    a.resize(n+1);
    st.resize(n*4);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    build(1,1,n);
 
    while(q--){
        ll t;
        cin>>t;
 
        if(t==1){
            ll idx,val; cin>>idx>>val;
            update(1,1,n,idx,val);
        }else{
            ll l,r; cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<"\n";
        }
 
 
 
 
    }
    
 
    
    return 0;
}
