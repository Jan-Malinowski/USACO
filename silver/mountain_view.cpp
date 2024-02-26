#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

const int INF=1e9;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){ return (a.first - a.second < b.first - b.second) || (a.first - a.second == b.first - b.second && a.second > b.second); }

int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, x, y;
    cin >> n;
    vector<pair<int, int> > mon(n);

    rep(i, n){
        cin >> x >> y;
        mon[i]={x, y};
    }

    int ans = n, currx=0, curry=0;
    sort(mon.begin(), mon.end(), cmp);

    rep(i, n){
        if(mon[i].second <= curry - (mon[i].first - currx)){
            ans --;
        }
        else{
            currx = mon[i].first;
            curry = mon[i].second;
        }
    }

    cout << ans;

    return 0;
}

