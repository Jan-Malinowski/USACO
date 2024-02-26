#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
struct Rect{
    int x1, y1, x2, y2;
    int area() {return (x2-x1)*(y2-y1);}
};

int intersect(Rect a, Rect b){
    int xOverlap = max(0, min(a.x2, b.x2)-max(a.x1, b.x1));
    int yOverlap = max(0, min(a.y2, b.y2)-max(a.y1, b.y1));
    return xOverlap * yOverlap;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    if((a.x1>=b.x1 && a.x2<=b.x2 && ((b.y2>=a.y2 && b.y1<=a.y2) || (a.y1>=b.y1 && a.y1<=b.y2)))){
        cout << a.area() - intersect(a, b);
    }
    else if((a.y1>=b.y1 && a.y2<=b.y2 && ((a.x2>=b.x1 && a.x2<=b.x2)||(a.x1>=b.x1 && a.x1<=b.x2)))){
        cout << a.area() - intersect(a, b);
    }
    else{
        cout << a.area();
    }
    
    

    return 0;
}