#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define int long long
const int INF=1e9;

int solve(vector<array<int, 2>>& points, int n) {
	sort(points.begin(), points.end());
	vector<int> lefts(n+1), downs(n+1), rights(n+1), ups(n+1);
	lefts[n] = downs[n] = INF;
	for (int i = n-1; i >= 0; --i) {
		int x = points[i][0], y = points[i][1];
		lefts[i] = min(x, lefts[i+1]);
		rights[i] = max(x, rights[i+1]);
		downs[i] = min(y, downs[i+1]);
		ups[i] = max(y, ups[i+1]);
	}
	int if_one = (rights[0] - lefts[0]) * (ups[0] - downs[0]);
	int cur_left = INF, cur_right = 0, cur_down = INF, cur_up = 0, ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x = points[i][0], y = points[i][1];
		cur_left = min(cur_left, x);
		cur_right = max(cur_right, x);
		cur_down = min(cur_down, y);
		cur_up = max(cur_up, y);
		int if_two = ((cur_right-cur_left) * (cur_up-cur_down)) + ((rights[i+1]-lefts[i+1]) * (ups[i+1]-downs[i+1]));
		ans = max(ans, if_one - if_two);
	}
	return ans;
}
signed main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n;
    cin >> n;
    vector<array<int, 2>> cor(n);
    rep(i, n){
        cin >> cor[i][0] >> cor[i][1];
    }

    int ans = solve(cor, n);
	for (auto& p : cor) swap(p[0], p[1]);
	ans = max(ans, solve(cor, n));
	cout << ans;

    return 0;
}

