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

    ll n,x;cin>>n>>x;

    vl a(n);

    for (ll i = 0; i < n; i++)cin >> a[i];

    sort(all(a));

    ll i = 0, j = n - 1;
    ll cnt = 0;

    while (i <= j) {
        if (a[i] + a[j] <= x) {
            i++; 
        }
        j--;
        cnt++;
    }

    cout<<cnt<<endl;


    
    return 0;
}
