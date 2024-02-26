#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;
const int MAX_DAYS = 1000;

const long long MOD = 1e9+7;

int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> earn(n);
    rep(i, n){
        cin >> earn[i];
    }

    vector<vector<int> > adj(n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
    }

    vector<vector<int> > dp(MAX_DAYS+1, vector<int>(n, -1));
    dp[0][0]=0;

    int ans=0;
    for(int d=0; d<MAX_DAYS; d++){
        for(int i=0; i<n; i++){
            if(dp[d][i]!=-1){
                for(int u:adj[i]){
                    dp[d+1][u]=max(dp[d+1][u], dp[d][i]+earn[u]);
                }
            }
        }
        ans = max(ans, dp[d][0]-(c*d*d));
    }
    cout << ans;

    

    return 0;
}