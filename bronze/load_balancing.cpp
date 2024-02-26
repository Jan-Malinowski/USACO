#include <iostream>

using namespace std;

#define rep(i, a) for(int i=0; i<a; i++)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n,b;
    cin >> n >> b;
    pair<int, int> cor[n];
    rep(i, n){
        cin >>cor[i].first >> cor[i].second;
    }
    int ans=INF;
    int ne=0, sw=0, se=0, nw=0;
    int x,y;

    for(int i=0; i<n; i++){
       for(int u=0; u<n; u++){
            ne=0, sw=0, se=0, nw=0;
            x=cor[i].first+1;
            y=cor[u].second+1;
            rep(j, n){
                if(cor[j].first>x && cor[j].second>y){
                    ne++;
                }
                else if(cor[j].first<x && cor[j].second>y){
                    sw++;
                }
                else if(cor[j].first<x && cor[j].second<y){
                    se++;
                }
                else{
                    nw++;
                }
            }
            int temp=max(ne, max(sw, max(se, nw)));
            ans=min(ans, temp);
       }
    }
    
    cout << ans;

    return 0;
}