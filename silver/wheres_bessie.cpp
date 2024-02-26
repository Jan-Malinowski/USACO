#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

const int _=20;
int n;
int grid[_][_];
bool visited[_][_];

int maxX, minX, maxY, minY;
map<int, int> color;

struct PCL
{
    int x1, y1, x2, y2;    
};

vector<PCL> pcl;


void floodfill(int x, int y, int curcolor){
    if(x < minX || y < minY || y > maxY || x > maxX || visited[x][y] || color[grid[x][y]] != curcolor){
        return;
    }
    visited[x][y]=true;
    floodfill(x-1, y, curcolor);
    floodfill(x+1, y, curcolor);
    floodfill(x, y-1, curcolor);
    floodfill(x, y+1, curcolor);
}

bool isPCL(int x1, int y1, int x2, int y2){
    vector<bool> hascolor(27, 0);
    vector<int> colorCount(2, 0);
    int colors=0;
    color.clear();
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(!hascolor[grid[i][j]]){
                color[grid[i][j]] = colors;
                ++colors;
                hascolor[grid[i][j]] = true;
            }
        }
    }
    if(colors!=2){
        return false;
    }
    minX=x1, maxX=x2, minY=y1, maxY=y2;
    rep(i, 20){
        rep(j, 20){
            visited[i][j]=false;
        }
    }
    for(int i=x1; i<=x2; i++){
        for(int j=y1; j<=y2; j++){
            if(!visited[i][j]){
                floodfill(i, j, color[grid[i][j]]);
                colorCount[color[grid[i][j]]]++;
            }
        }
    }

    return ((colorCount[0]==1 && colorCount[1]>1) || (colorCount[1]==1 && colorCount[0]>1));
}

bool is_subset(int a, int b){
    return (pcl[a].x1 >= pcl[b].x1) && (pcl[a].x2 <= pcl[b].x2) && (pcl[a].y1 >= pcl[b].y1) && (pcl[b].y2 >= pcl[a].y2);
}

bool optimal_pcl(int a){
    rep(i, pcl.size()){
        if(i!=a && is_subset(a, i)){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0); 

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin >> c;
            grid[i][j] = (c - 'A' + 1);
        }
    }

    rep(x1, n){
        rep(y1, n){
            rep(x2, n){
                rep(y2, n){
                    if(isPCL(x1, y1, x2, y2)){
                        pcl.push_back({x1, y1, x2, y2});
                    }
                }
            }
        }
    }
    int ans=0;
    rep(i, pcl.size()){
        if(optimal_pcl(i)){
            ans++;
        }
    }
    cout << ans;
    
    
    return 0;
}