#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;

const long long MOD = 1e9+7;

struct DSU {
	vector<int> e;
	void init(int n) { e = vector<int>(n, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); };
	bool sameSet(int x, int y) { return get(x) == get(y); };
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

bool cmp(const pair<int, pair<int, int>> &a,
         const pair<int, pair<int, int>> &b) {
	return a.second.second > b.second.second;
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<pair<int, pair<int, int> > > edges(n-1);
    rep(i, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = make_pair(w, make_pair(u, v));
    }
    vector<pair<int, pair<int, int> > > queries(q);

    rep(i, q){
        int v, k;
        cin >> k >> v;
        v--;
        queries[i] = make_pair(i, make_pair(v, k));
    }

    sort(queries.begin(), queries.end(), cmp);
	sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    DSU dsu;
    dsu.init(n);
    vector<int> sol(q);
    int idx=0;

    for(auto query : queries){
        int v = query.second.first;
		int curK = query.second.second;
		while (idx < (int)edges.size() && edges[idx].first >= curK) {
			dsu.unite(edges[idx].second.first, edges[idx].second.second);
			idx++;
		}
		sol[query.first] = dsu.size(v) - 1;
    }

    for(auto x : sol){
        cout << x << "\n";
    }

    return 0;
}