#include <iostream>
#include <string>
#include <set>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n,m,ans=0;
    cin >> n >> m;
    string spot[n], plain[n];
    rep(i, n){
        cin >> spot[i];
    }
    rep(i, n){
        cin >> plain[i];
    }
    bool flag=false;
    string temp="AAA", temp1="AAA";
    set<string> spotty;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int x=j+1; x<m; x++){
                flag=false;
                spotty.clear();
                rep(g, n){
                    temp[0]=spot[g][i];
                    temp[1]=spot[g][j];
                    temp[2]=spot[g][x];
                    spotty.insert(temp);
                }
                rep(g, n){
                    temp1[0]=plain[g][i];
                    temp1[1]=plain[g][j];
                    temp1[2]=plain[g][x];
                    if(spotty.count(temp1)){
                        flag=true;
                        break;
                    }
                }    
                if(flag==false){
                    ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}

