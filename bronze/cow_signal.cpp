#include <iostream>
#include <string>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int m,n,k;
    cin >> m >> n >> k;
    string word_in, word_out="";
    
    rep(i, m){
        cin >> word_in;
        word_out="";
        rep(j, n){
            rep(x, k){
                word_out+=word_in[j];
            }
        }
        rep(j, k){
            cout << word_out << "\n";
        }
    }
    return 0;
}