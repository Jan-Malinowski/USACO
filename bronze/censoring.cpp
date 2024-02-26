#include <iostream>
#include <string>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string word, censor;
    cin >> word >> censor;
    string ans;
    int x=censor.size(), y=word.size();
    for(int i=0; i<y; i++){
        ans+=word[i];
        if(ans.size()>x && ans.substr(ans.size() - x) == censor){
            ans.erase(ans.size()-x, x);
        }
    }

    cout << ans;

    return 0;
}