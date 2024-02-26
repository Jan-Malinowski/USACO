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
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    int tab[n], temp[n];
    int ans=0;
    rep(i, n){
        cin >> tab[i];
        temp[i] = tab[i];
    }
    sort(temp, temp+n);

    rep(i, n){
        if(tab[i]!=temp[i]){
            ans++;
        }
    }
    cout <<  max(0, ans-1);
    return 0;
}