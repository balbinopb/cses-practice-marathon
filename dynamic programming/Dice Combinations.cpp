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

const ll MOD = 1e9 + 7;




int main() {
    fast_io;

    ll n; cin>>n;
    
    vl dp(n + 1, 0);
    dp[0] = 1; 

    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= 6; d++) {
            if ((i-d)>= 0) {
                dp[i] = (dp[i] + dp[i - d]) %MOD;
            }
        }
    }

    cout<<dp[n]<<"\n";
    
    return 0;
}
