#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int width=max(x2,x4)-min(x1,x3);
    int length=max(y2,y4)-min(y1,y3);
    if(width>=length){
        cout << width*width;
    }
    else{
        cout << length*length;
    }

    

    return 0;
}