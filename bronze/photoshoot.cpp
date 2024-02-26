#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)

const int INF=1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, ans=0;
    cin >> n;
    string a;
    cin >> a;

    for(int i=n-1; i>0; i-=2){
        if(a[i] == a[i-1]){continue;}
        if(a[i]=='G' && ans%2==1){
            ++ans;
        }
        if(a[i]=='H' && ans%2==0){
            ++ans;
        }
    }
    cout << ans;

    return 0;
}