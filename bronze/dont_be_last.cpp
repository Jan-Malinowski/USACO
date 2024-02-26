#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n;
    cin >> n;
    map<string, int> m;
    string x, name;
    int z, minv=INF, ans=0, cur=INF;
    rep(i, n){
        cin >> x >> z;
        m[x]+=z;
    }
    if(m.size()<7){
        minv=0;
    }
    else{
        for(auto g:m){
            minv=min(minv, g.second);
        }
    }  
    
    for(auto g:m){
        if(g.second>minv && g.second<cur){
            cur=g.second;
            name=g.first;
            ans=1;
        }
        else if(g.second == cur){
            ++ans;
        }
    }
    cout << (ans == 1 ? name : "Tie") << "\n";
    

    return 0;
}