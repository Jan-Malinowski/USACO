#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int n;
vector<int> adj[200];
int cows_reached=0;
bool visited[200];

struct walkie
{
    int x, y, p;
};

void dfs(int i){
    if(visited[i]){
        return;
    }
    visited[i]=true;
    cows_reached++;
    for(int x : adj[i]){
        dfs(x);
    }
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);    
    cin >> n;
    vector<walkie> cow(n);
    rep(i, n){
        cin >> cow[i].x >> cow[i].y >> cow[i].p;
    }

    rep(i, n){
        rep(j, n){
            int distX=cow[i].x-cow[j].x, distY=cow[i].y-cow[j].y;
            if(distX*distX+distY*distY <= cow[i].p*cow[i].p){
                adj[i].push_back(j);
            }
        }
    }
    int max_reached=0;
    rep(i, n){
        cows_reached=0;
        fill(visited, visited+n, false);
        dfs(i);
        max_reached=max(max_reached, cows_reached);
    }

    cout << max_reached;
    
    return 0;
}