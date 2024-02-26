#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
typedef long long ll;

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_map<ll, ll> m;
    int n, x;
    cin >> n;
    ll y, z;
    rep(i, n){
        cin >> x;
        if(x==0){
            cin >> y >> z;
            m[y]=z;
        }
        else{
            cin >> y;
            cout << m[y] << "\n";
        }
    }

    return 0;
}

// 972 ms	62.72 Mib <- map
// 727 ms	43.21 Mib <- unordered_map