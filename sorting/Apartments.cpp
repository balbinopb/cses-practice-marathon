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

    ll n,m,k; cin>>n>>m>>k;

    vl a(n),b(m);

    for (ll i = 0; i < n; i++)cin >> a[i];
    for (ll i = 0; i < m; i++)cin >> b[i];

    sort(all(a));    
    sort(all(b));
    
    ll i = 0, j = 0, cnt = 0;

    while (i < n && j < m) {
        if (b[j] < a[i] - k) {
            j++; // apartment too small
        } 
        else if (b[j] > a[i] + k) {
            i++; // apartment too big
        } 
        else {
            cnt++; // match found
            i++;
            j++;
        }
    }

    cout << cnt << "\n";
    


    
    return 0;
}
