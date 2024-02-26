#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ifstream in("mixmilk.in");
    ofstream out("mixmilk.out");
    int milk_now[3], milk_cop[3], bucket1, bucket2;
    rep(i, 3){
        in >> milk_cop[i] >> milk_now[i];
    }
    for(int i=0; i<100; i++){
        bucket1=i%3;
        bucket2=(i+1)%3;

        int count = min(milk_now[bucket1], milk_cop[bucket2]-milk_now[bucket2]);
        milk_now[bucket1]-=count;
        milk_now[bucket2]+=count;
    }

    for(int x:milk_now){
        out << x << "\n";
    }

    return 0;
}