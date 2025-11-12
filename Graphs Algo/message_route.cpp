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

vector<int> bfs(int start, int end, vvi &adj,vi &dist) {
    int n = adj.size();
    vi parent(n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[end] == -1) return {};

    // reconstruct path
    vi path;
    for (int cur = end; cur != -1; cur = parent[cur])
        path.pb(cur);

    reverse(all(path));
    return path;
}

int main() {
    fast_io;

    cin >> n >> m;

    vvi adj(n+1);
    vi vis(n+1,-1);

    for (int i = 1; i <= m; i++){
        int a,b;
        cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> path = bfs(1, n, adj,vis);

    if (path.empty()) {
        cout << "IMPOSSIBLE\n";

    } else {
        cout << path.size() <<"\n";
        for (int x : path) {
            cout << x << " ";
        }
        cout << "\n";
    }

    
    

    
    return 0;
}
