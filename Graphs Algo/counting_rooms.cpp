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
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x,int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            if (!vis[nx][ny] && grid[nx][ny] == '.') {
                dfs(nx, ny);
            }
    }
    
}




int main() {
    fast_io;

    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) cin >> grid[i];

    char start,end;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(grid[i][j]=='A'){
                start=grid[i][j];
            }
            if(grid[i][j]=='B'){
                end=grid[i][j];
            }

        }
        
    }
    

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << "\n";

    
    return 0;
}
