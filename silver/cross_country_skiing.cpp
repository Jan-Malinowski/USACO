#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int _=500;
int row, col;
vector<vector<int>> heights, flags;
vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vector<bool>>& vis, int r, int c, int x) {
    vis[r][c] = true;
    for (auto& d : dirs) {
        int dr = r + d[0], dc = c + d[1];
        bool out = dr < 0 || dc < 0 || dr >= row || dc >= col;
        if (!out && !vis[dr][dc] && abs(heights[r][c] - heights[dr][dc]) <= x) {
            dfs(vis, dr, dc, x);
        }
    }
}

bool ok(int x){
    vector<vector<bool>> vis(row, vector<bool>(col));
    for (int r = 0; r < row; r++) {
        bool found = false;
        for (int c = 0; c < col; c++) {
            if (flags[r][c] == 1) {
                found = true;
                dfs(vis, r, c, x);
                break;
            }
        }
        if (found) break;
    }
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (flags[r][c] == 1 && !vis[r][c]) return false;
            }
    }
    return true;
}

int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0); 

    cin >> row >> col;
    heights = flags = vector<vector<int>>(row, vector<int>(col));
    for (auto& row : heights) {
        for (int& x : row) {
            cin >> x;
        }
    }
    for (auto& row : flags) {
        for (int& x : row) {
            cin >> x;
        }
    }
    int lo = 0, hi = 1e9, ans = 1e9;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans;
    
    
    return 0;
}