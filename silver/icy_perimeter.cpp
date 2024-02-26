#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int _=1000;
int row;
bool visited[_][_];
char grid[_][_];
int cur_per=0;
int cur_size=0;

void floodfill(int r, int c){
    if((r<0 || r>=row || c<0 || c>=row) || grid[r][c]=='.'){
        cur_per++;
        return;
    }
    if(visited[r][c]){
        return;
    }
    cur_size++;
    visited[r][c]=true;
    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}


int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);     
    cout.tie(0); 

    cin >> row ;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            cin >> grid[i][j];
        }
    }
    int max_ans=0, max_per=0;

    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            if(!visited[i][j] && grid[i][j]=='#'){
                floodfill(i, j);
                if(cur_size>max_ans || (cur_size==max_ans && cur_per<max_per)){
                    max_ans=cur_size;
                    max_per=cur_per;
                }
                cur_per=0;
                cur_size=0;
            }
        }
    }
    cout << max_ans << ' ' << max_per;
    
    return 0;
}