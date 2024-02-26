#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ifstream in("shell.in");
    ofstream out("shell.out");
    string shells="123";
    int n, a, b, g, ans1=0, ans2=0, ans3=0;
    
    in >> n;

    rep(i, n){
        in >> a >> b >> g;
        swap(shells[a-1], shells[b-1]);
        if(shells[g-1]=='1'){
            ans1++;
        }
        else if(shells[g-1]=='2'){
            ans2++;
        }
        else{
            ans3++;
        }
    }
    out << max({ans1, ans2, ans3});

    return 0;
}