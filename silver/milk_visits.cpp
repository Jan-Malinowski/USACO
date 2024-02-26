#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;

vector<int> adj[_], farm(_), comp(_);
bool visited[_];
int curComp;

void dfs(int node){
    if(visited[node]){
        return;
    }
    comp[node]=curComp;
    visited[node]=true;
    for(int x : adj[node]){
        if(farm[node] == farm[x]){
            dfs(x);
        }
    }
}

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string cows;
    cin >> cows;
    
    rep(i, n){
        farm[i] = cows[i]=='H';
    }
    rep(i, n-1){
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    curComp=1;
    rep(i, n){
        if(!comp[i]){
            dfs(i);
            curComp++;
        }
    }

    rep(i, m){
        int a, b;
        char c;
        cin >> a >> b >> c;
        int curType = c == 'H';
        --a; --b;
        if(comp[a] != comp[b] || farm[a]==curType){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }

    return 0;
}