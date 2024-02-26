#include <iostream>
#include <string>

using namespace std;

#define rep(i, a) for(int i=0; i<a; i++)

string spot[100], plain[100];

bool check(int m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(spot[i][m]==plain[j][m]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n,m, ans=0;
    cin >> n >> m;
    rep(i, n){
        cin >> spot[i];
    }
    rep(i, n){
        cin >> plain[i];
    }

    rep(i, m){
        if(check(i, n)){
            ans++;
        }
    }

    cout << ans;
    
    

    return 0;
}