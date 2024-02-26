#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

const int INF=1e5, INT_M=1e9;
int n, m, xu=0, xd=INT_M, yl=INT_M, yr=0;
vector<int> adj[INF];
pair<int, int> cows[INF];
bool visited[INF];

void dfs(int i){
    if(visited[i]){
        return;
    }
    visited[i]=true;
    xu=max(xu, cows[i].first);
    xd=min(xd, cows[i].first);
    yl=min(yl, cows[i].second);
    yr=max(yr, cows[i].second);
    
    for(int x : adj[i]){
        dfs(x);
    }
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);    
    cin >> n >> m;

    rep(i, n){
        cin >> cows[i].first >> cows[i].second;
    }

    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans=1e9;
    rep(i, n){
        if(!visited[i]){
            xu=-1, xd=INT_M, yl=INT_M, yr=-1;
            dfs(i);
            ans = min(ans, 2*(xu-xd)+2*(yr-yl));
        }
    }

    cout << ans;
    
    return 0;
}