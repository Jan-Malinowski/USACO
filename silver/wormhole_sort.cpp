#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

const int q = 1e5;
int n, m;
vector<pair<int, int> > adj[q];
int visited[q];
int cows[q];

void dfs(int i, int k, int group){

    visited[i]=group;
    for(auto x:adj[i]){
        if(!visited[x.first] && x.second >= k){
            dfs(x.first, k, group);
        }
    }
}

bool sear(int k){
    fill(visited, visited+n, 0);
    int groups = 0;
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            groups++;
            dfs(i, k, groups);
        }
    }
    for(int i=0; i<n; i++){
        if(visited[cows[i]-1] != visited[i]){
            return false;
        }
    }
    return true;
}

int main(){
    (void)!freopen("wormsort.in", "r", stdin);
    (void)!freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int maxweight=0;
    rep(i, n){
        cin >> cows[i];
    }
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        maxweight=max(maxweight, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int ready=0;
    rep(i, n){
        if(cows[i]-1 == i){
            ready++;
        }
    }
    if(ready==n){
        cout << -1;
        return 0;
    }

    int l=0, h=maxweight, ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(sear(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            h=mid-1;
        }
    }
    cout << ans;


    return 0;
}

