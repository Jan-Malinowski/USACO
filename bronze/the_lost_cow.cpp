#include <iostream>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x,y,xx;
    cin >> x >> y;
    int dis = 0;
    int len = 1;
    bool right = true;
    int pos=x;
    while(true){
        if(right){
            if((x+len)>=y && x<=y){
                dis += abs(y-pos);
                break;
            }
            else{
                right = false;
                dis += abs(x+len - pos);
                pos = x+len;
            }
        }       
        else{
            if((x-len)<=y && x>=y){
                dis += abs(y-pos);
                break;
            }
            else{
                right = true;
                dis += abs(x-len - pos);
                pos = x-len;
            }
        }
        cerr<<pos<<endl;
        len *= 2;
    }
    cout<<dis<<endl;
    return 0;
}