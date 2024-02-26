#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

const int INF=1e9;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int> >tab;
    int x, y;
    tab.push_back({0, 0});
    rep(i, n){
        cin >> x >> y;
        tab.push_back({x, y});
    }
    tab.push_back({INF, INF});
    sort(tab.begin(), tab.end());
    int tot = 0, mn = INF, l_end = -1, l_far = -1, r_end = -1;
    for (int i = 1; i <= n; i++) {
        l_end = max(tab[i].first, tab[i - 1].second);
        l_far = max(l_far, l_end);
        r_end = min(tab[i].second, tab[i + 1].first);
        mn = min(mn, max(0, r_end - l_end));
        tot += max(0, tab[i].second - l_far);
    }
    cout << tot-mn;


    return 0;
}

