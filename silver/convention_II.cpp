#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define start second.first
#define duration second.second
#define prio first
using cow = pair<int, pair<int, int>>;

bool cnt(const cow a, const cow b) {
        if (a.start != b.start) return a.start < b.start;
        else return a.prio > b.prio;
}

int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, ans=0;
    cin >> n;
    vector<cow> cows(n+1);
   for(int i=n; i>0; i--){
        int x, y;
        cin >> x >> y;
        cows[i]={i, {x, y}};
    }
    cows[0]={0, {1e9, 0}};
    sort(cows.begin(), cows.end(), cnt);
    priority_queue<cow> waiting;
    cow gg;
    int time=0;
    int x=0;
    for(int i=0; i<n+1; ){
        cow c = cows[i];
        if (c.start > time && waiting.empty()) {
            time = c.start + c.duration;
            ++i; 
        }

        else if (c.start > time) {
            gg = waiting.top();
            waiting.pop();

            ans = max(ans, time - gg.start);

            time += gg.duration;
        }

        else {
            waiting.push(c);
            ++i; 
        }
    }

    cout << ans;
    return 0;
}