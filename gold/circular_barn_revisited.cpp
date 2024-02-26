#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <deque>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;

const long long MOD = 1e9+7;

int main(){
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    deque<int> r(n);
    rep(i, n){
        cin >> r[i];
    }

    long long min_dist = INT_MAX;

    for(int start_pos=0; start_pos<n; start_pos++){
        vector<vector<long long> > dp(k+1, vector<long long>(n+1, INT64_MAX));
        dp[0][n]=0;

        for(int used_door=1; used_door<=k; used_door++){
            for(int i=0; i<n; i++){
                long long partial_dist=0;
                for(int j=i+1; j<=n; j++){
                    partial_dist+=r[j-1]*(j-i-1);
                    long long new_dist=dp[used_door-1][j];
                    if(new_dist<INT64_MAX){
                        new_dist+=partial_dist;
                    }
                    dp[used_door][i]=min(dp[used_door][i], new_dist);
                }
            }
        }
        min_dist=min(min_dist, dp[k][0]);
        int first_room=r.front();
        r.pop_front();
        r.push_back(first_room);
    }

    cout << min_dist;


    return 0;
}