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

int n, m;



void dfs(int node,vi &vis,vvi &adj) {
    vis[node] = 1;
    for (auto nxt : adj[node]) {
        if (!vis[nxt]) {
            dfs(nxt,vis,adj);
        }
    }
}



int main() {
    fast_io;

    cin >> n >> m;

    vvi adj(n+1);
    vi vis(n+1,0);

    for (int i = 1; i <= m; i++){
        int a,b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi res;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res.pb(i);
            dfs(i,vis,adj);
        }
    }
    
    

    cout << res.size() - 1 << "\n";

    for (int i = 0; i + 1 < res.size(); i++) {
        cout << res[i] << " " << res[i + 1] << "\n";
    }

    
    return 0;
}
