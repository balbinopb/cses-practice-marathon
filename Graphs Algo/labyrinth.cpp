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
#define vc vector<char>
#define vb vector<bool>
#define pii pair<int,int>
#define vv(type) vector<vector<type>>
#define DIGITS(x) ((int)to_string(x).size())


int n,m;

// direction
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dirChar[4] = {'U', 'D', 'L', 'R'};


void bfs(vv(char) &adj,pair<int,int> start,vv(int) &level,vv(pii) &parent){
    
    
    queue<pii> q;
    
    q.push(start);
    
    level[start.first][start.second]=0;
    
    while(!q.empty()){
        auto[x,y]=q.front();
        
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int newX= dx[i]+x;
            int newY= dy[i]+y;
            
            if(newX<0 || newY<0 || newX>=n || newY>=m) continue;
            
            if(level[newX][newY]>-1 || adj[newX][newY]=='#') continue;
            
            level[newX][newY]=level[x][y]+1;
            parent[newX][newY]={x,y};
            
            q.push({newX,newY});
            
            
        }
        
    }
    
}



int main() {
    fast_io;
    
    cin>>n>>m;
    
    vv(char) adj(n, vc(m));
    for (int i = 0; i < n; i++){
        for (int j = 0;j < m; j++){
            cin>>adj[i][j];
        }
        
    }
    
    
    
    pii start,end;
    
    for (int i = 0; i < n; i++){
        for (int j = 0;j < m; j++){
            if(adj[i][j]=='A'){
                start={i,j};
            }
            if(adj[i][j]=='B'){
                end={i,j};
            }
        }
    }

    vv(int) level(n,vi(m,-1));//for tracking level of node
    vv(pii) parent(n,vector<pii>(m,{-1,-1}));//for tracking tree
    
    bfs(adj,start,level,parent);


    if(level[end.first][end.second]==-1) {
        cout<<"NO"<<"\n";
    }else{
        
        string path="";
    
        pii cur= end;
    
        while(cur!=start){
            pii p = parent[cur.first][cur.second]; 
    
            for (int i = 0; i < 4; i++){
    
                if(p.first + dx[i] == cur.first && p.second + dy[i] == cur.second){
                    path += dirChar[i];
                    break;
                }
            }
            cur=p;
            
        }
    
        reverse(all(path));
        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    }


    return 0;
}
