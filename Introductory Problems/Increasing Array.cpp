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





int main() {
    fast_io;

    int n; cin>>n;

    vl a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    
    ll cnt=0;
    for (int i = 1; i < n; i++) {
        if(a[i]<a[i-1]) {
            cnt+=a[i-1]-a[i];
            a[i] +=a[i-1]-a[i];
        }
    }

    cout<<cnt<<"\n";
    
    return 0;
}
