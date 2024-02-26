#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _ = 200;
int n, k, r, cows=0;
int grid[_][_];

void floodfill(int r, int c){
    if(r<0 || r>=n || c<0 || c>=n || grid[r][c] >= 2){
        return;
    }
    else if(grid[r][c]==1){
        cows++;
    }
    grid[r][c]=3;
    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}

int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0); 

    cin >> n >> k >> r;
    n*=2;
    rep(i, r){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        x1*=2; y1*=2; x2*=2; y2*=2;
        if(x1 == x2){
            int t = (y1+y2)/2;
            grid[x1][t] = 2;
            grid[x1+1][t] = 2;
            if(x1 > 0){
                grid[x1-1][t] = 2;
            }
        }
        else{
            int t = (x1+x2)/2;
            grid[t][y1] = 2;
            grid[t][y1+1] = 2;
            if(y1 > 0){
                grid[t][y1-1] = 2;
            }
        }
    }
    rep(i, k){
        int x, y;
        cin >> x >> y;
        x--; y--;
        x*=2; y*=2;
        grid[x][y]=1;
    }
    vector<int> c;
    rep(i, n){
        rep(j, n){
            if(grid[i][j]<2){
                cows=0;
                floodfill(i, j);
                c.push_back(cows);
            }
        }
    }
    int ans=0;
    for(int i=0; i<c.size()-1; i++){
        for(int j=i+1; j<c.size(); j++){
            ans += c[i]*c[j];
        }
    }
    cout << ans;
    
    return 0;
}