#include <iostream>
#include <string>

using namespace std;

#define rep(i, a) for(int i=0; i<a; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    int n,k,ans=0;
    cin >> k >> n;
    int tab[n][k]; //krowa numer konkurencji
    int x;
    rep(i, k){
        rep(j, n){
            cin >> x;
            tab[x-1][i]=j;
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int temp=tab[i][0]-tab[j][0];
            bool check=true;
            for(int x=1; x<k; x++){
                if((tab[i][x]-tab[j][x])*temp<0){
                    check=false;
                    break;
                }
            }
            if(check){
                ans++;
            }
        }
    }
    
    cout << ans;
    

    return 0;
}