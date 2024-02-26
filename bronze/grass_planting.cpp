#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int> > neighbors(n+1);

    int x, y;
    rep(i, n-1){
        cin >> x >> y;
        neighbors[x].push_back(y);
        neighbors[y].push_back(x);
    }
    int ans=0;
    rep(i, n+1){
        int temp = neighbors[i].size();
        ans = max(ans, temp);
    }

    cout << ans+1;

    return 0;
}