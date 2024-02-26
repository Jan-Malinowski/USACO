#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n, l, x=0, y=0;
    int ans=9999999, time=0;
    char c;
    vector<pair<int, int>> path; // also ok int visited[x][y]=-1  if(!=-1) min(time-visited) visited[x][y]=time;
    path.push_back(make_pair(x, y));


    cin >> n;
    rep(i, n){
        cin >> c >> l;
        rep(j, l){
            time++;
            if(c=='N'){
                y++;
            }
            else if(c=='E'){
                x++;
            }
            else if(c=='S'){
                y--;
            }
            else{
                x--;
            }
            for (int z = path.size()-1; z > 0; z--) {
                if (path[z].first == x && path[z].second == y) {
                    ans = min(ans, time-z);
                }
            }
            path.push_back(make_pair(x, y));
            
        } 
    }
    if(ans==9999999){
        ans=-1;
    }
    cout << ans;

    return 0;
}