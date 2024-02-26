#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    string s;
    int n;
    cin >> n >> s;
    int ans=INF;
    set<string> p;
    bool flag=false;

    for(int i=1; i<=n; ++i){
        flag=false;
        rep(j, n-i+1){
            ans=i;
            if(p.count(s.substr(j,i))){
                flag=true;
                break;
            }
            else{
                p.insert(s.substr(j,i));
            }
        }
        if(!flag){
            break;
        }
    }
    cout << ans;
    

    return 0;
}