#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    vector<int> a(1001);
    int n, s, t, b, ans=0;
    cin >> n;
    rep(i, n){
        cin >> s >> t >> b;
        for(int j=s; j<=t; j++){
            a[j]+=b;
        }
    }
    n=1001;
    rep(i, n){
        ans = max(a[i], ans);
    }

    cout << ans;

    return 0;
}