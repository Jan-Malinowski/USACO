#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)


const int q=1e5;
int n, m;
vector<pair<int, int> > adj[q];
vector<int> states(q);
bool impossible = false;

void dfs(int node, bool color){
    if(states[node]!=2 && states[node]!=color){
        impossible = true;
        return;
    }
    if(states[node]==color){
        return;
    }
    states[node]=color;
    for(auto x:adj[node]){
        if(x.second == 1){
            dfs(x.first, color);
        }
        else{
            dfs(x.first, !color);
        }
    }
}


int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);    
    
    cin >> n >> m;

    rep(i, m){
        char a;
        int b, c;
        cin >> a >> b >> c;
        b--; c--;
        if(a=='S'){
            adj[b].push_back({c, 1});
            adj[c].push_back({b, 1});
        }
        else{
            adj[b].push_back({c, 2});
            adj[c].push_back({b, 2});
        }
    }
    
    states.resize(n);
    fill(states.begin(), states.end(), 2);

    int ans=0;
    rep(i, n){
        if(states[i]!=2){
            continue;
        }
        ans++;
        dfs(i, false);
        if(impossible){
            break;
        }
    }

    if(impossible){
        cout << 0;
    }
    else{
        cout << 1;
        rep(i, ans){
            cout << 0;
        }
    }
    
    return 0;
}