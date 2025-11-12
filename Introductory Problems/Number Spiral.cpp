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

int main(){
    fast_io;
    int t; cin>>t;

    while(t--){
        ll x, y;
        cin >> x >> y;
        ll n = max(x, y);
        ll res;
        if (n % 2 == 0) {
            if (x == n) {
                res = n * n - y + 1;
            } else {
                res = (n - 1) * (n - 1) + x;
            }
        } else {
            if (y == n) {
                res = n * n - x + 1;
            } else {
                res = (n - 1) * (n - 1) + y;
            }
        }
        cout <<res<<"\n";
    }
}