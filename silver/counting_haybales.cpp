#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0);    

    int n, q;
    cin >> n >> q;
    vector<int> hays(n);
    rep(i, n){
        cin >> hays[i];
    }
    sort(hays.begin(), hays.end());

    rep(i, q){
        int x, y;
        cin >> x >> y;
        cout << (--upper_bound(hays.begin(), hays.end(), y)) - lower_bound(hays.begin(), hays.end(), x)+1 << "\n";
    }

    return 0;
}