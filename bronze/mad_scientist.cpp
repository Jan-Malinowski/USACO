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
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool next=false;
    int ans=0;

    rep(i, n){
        if(a[i]!=b[i] && next==false){
            next=true;
            ans++;
        }
        else if(a[i]==b[i]){
            next = false;
        }
    }
    cout << ans;
    return 0;
}