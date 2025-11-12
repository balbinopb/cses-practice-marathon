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


// total pairs on k×k board
ll totalPairs(ll k) {
    return k * k * (k * k - 1) / 2;
}

// ---------- PIECE FUNCTIONS ----------
ll twoKnights(ll k) {
    if (k < 1) return 0;
    if (k < 3) return totalPairs(k); // for k=1,2 attacking term=0
    return totalPairs(k) - 4 * (k - 1) * (k - 2);
}

ll twoRooks(ll k) {
    return totalPairs(k) - k * k * (k - 1);
}

ll twoKings(ll k) {
    return totalPairs(k) - (2 * k * (k - 1) + 2 * (k - 1) * (k - 1));
}

ll twoBishops(ll k) {
    ll diagSum = 0;
    // main diagonals
    for (int len = 1; len <= k; ++len)
        diagSum += (len >= 2) ? (ll)len * (len - 1) / 2 : 0;
    // anti-diagonals
    for (int len = 1; len <= k - 1; ++len)
        diagSum += (len >= 2) ? (ll)len * (len - 1) / 2 : 0;

    ll attacking = 2 * diagSum;
    return totalPairs(k) - attacking;
}

ll twoQueens(ll k) {
    // Queens attack as Rooks + Bishops
    ll attacking_rooks = k * k * (k - 1);
    ll diagSum = 0;
    for (int len = 1; len <= k; ++len)
        diagSum += (len >= 2) ? (ll)len * (len - 1) / 2 : 0;
    for (int len = 1; len <= k - 1; ++len)
        diagSum += (len >= 2) ? (ll)len * (len - 1) / 2 : 0;
    ll attacking_bishops = 2 * diagSum;
    return totalPairs(k) - (attacking_rooks + attacking_bishops);
}


int main() {
    fast_io;

    ll n; cin>>n;

    for (int k = 1; k <= n; ++k) {

        cout << twoKnights(k) <<"\n";
    }
    

    
    return 0;
}
