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



int main(){
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int> > points(n+2);
    unordered_map<int, vector<int> > lines[2];

    rep(i, n+2){
        cin >> points[i].first >> points[i].second;
		lines[0][points[i].first].push_back(i);
		lines[1][points[i].second].push_back(i);
    }

    queue<pair<int, bool> > q;
    q.push({0, true});
    q.push({0, false});
    vector<int> dist(n+1, 1e9);
    dist[0]=0;
    while(!q.empty()){
        int curr = q.front().first;
        bool beamdir = q.front().second;
        q.pop();
        int dir = (beamdir ? 0 : 1);
        int coord = (beamdir ? points[curr].first : points[curr].second);
        for(int point : lines[dir][coord]){
            if(dist[point]==1e9){
                q.push({point, !beamdir});
                dist[point]=dist[curr]+1;
            }
        }
    }

    cout << (dist[1] == 1e9 ? -1 : dist[1] - 1) << endl;

    return 0;
}