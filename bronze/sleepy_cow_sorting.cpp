#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;
    int tab[n];
    rep(i, n){
        cin >> tab[i];
    }
    for(int i=n-2; i>=0; i--){
        if(tab[i]>tab[i+1]){
            cout << i+1;
            return 0;
        }
    }
    cout << 0;
    

    return 0;
}