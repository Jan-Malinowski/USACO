#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <deque>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;

const long long MOD = 1e9+7;

string num;
ll dp[19][50][2][2];

void reset(){
    rep(i, 19){
        rep(j, 50){
            rep(k, 2){
                rep(l, 2){
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
}

ll solve_dp(int pos, int k, bool under, bool started, int targ, int targ2){
    if(pos==num.size()){
        if(!started){
            return 0;
        }
        if(targ2 != -1){
            if(k==20){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(k>=20){
            return 1;
            }
        else{
            return 0;
        }
    }
    if(dp[pos][k][under][started]!=-1){
        return dp[pos][k][under][started];
    }

    ll ans=0;
    rep(i, 10){
        int digit_diff = num[pos]-'0';
        if(!under && i > digit_diff){
            break;
        }
        bool is_under = under;
        if(i < digit_diff){
            is_under =  true;
        }

        bool is_started = started || i!=0;

        if(is_started && targ2!=-1 && i!=targ && i!=targ2){
            continue;
        }

        int new_k = k;
        if(is_started){
            if(targ==i){
                new_k = k+1;
            }
            else{
                new_k = k-1;
            }
        }
        ans += solve_dp(pos+1, new_k, is_under, is_started, targ, targ2);
    }

    return dp[pos][k][under][started] = ans;
}

ll count_interesting_to(ll ubound){
    num = to_string(ubound);
    ll ans=0;
    rep(i, 10){
        reset();
        ans+=solve_dp(0, 20, false, false, i, -1);
    }

    ll duplicates=0;
    rep(i, 10){
        rep(j, 10){
            reset();
            duplicates+=solve_dp(0, 20, false, false, i, j);
        }
    }

    return ans - (duplicates/2);
}

int main(){
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    ll x, y;
    cin >> x >> y;
    cout << count_interesting_to(y)-count_interesting_to(x-1);

    return 0;
}