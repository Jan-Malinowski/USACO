#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    int ans, s, x, temp, r;
    rep(i, n){
        temp=0, s=1, ans=0;
        cin >> x;
        r=k;
        while(r>0 && s<x){
            ++ans;
            r -= s;
            ++s;
        }
        bool flag=true;
        while(r>0){
            ++ans;
            r-=s;
            if(flag){
                flag=false;
            }
            else{
                s++;
                flag=true;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}