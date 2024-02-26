#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 1e5;

const long long MOD = 1e9+7;

int main(){
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(2*n+1, 0);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y]--;
    }

    vector<long long> pow(n);

    pow[0]=1;
    for(int i=1; i<=n-1; i++){
        pow[i]=pow[i-1]*2%MOD;
    }

    int open=0;
    long long ans=0;

    for(int i=0; i<=n*2; i++){
        open+=a[i];

        if(a[i]==1){
            ans = (ans+pow[n-open])%MOD;
        }
    }

    cout << ans;

    return 0;
}