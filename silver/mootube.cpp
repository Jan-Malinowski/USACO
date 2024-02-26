#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 5000;

vector<vector<pair<int, int> > > neighbors(_);
vector<bool> visited(_);
int threshold;
int num_reached;

void search(int node){
    visited[node]=true;
    for(auto x : neighbors[node]){
        if(!visited[x.first] && x.second >= threshold){
            num_reached++;
            search(x.first);
        }
    }
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0); 
    int n, q;
    cin >> n >> q;
    rep(i, n-1){
        int a, b, r;
        cin >> a >> b >> r;
        a--;
        b--;
        neighbors[a].push_back({b, r});
        neighbors[b].push_back({a, r});
    }
    
    rep(i, q){
        int s;
        cin >> threshold >> s;
        s--;
        num_reached = 0;
        fill(visited.begin(), visited.end(), false);
        search(s);

        cout << num_reached << '\n';
    }
    return 0;
}