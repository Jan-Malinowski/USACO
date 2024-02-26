#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ifstream in("blocks.in");
    ofstream out("blocks.out");
    int letters[26]={0}, n;
    string front, back;

    in >> n;

    rep(i, n){
        int letters_a[26]={0}, letters_b[26]={0};
        in >> front >> back;
        for(int j=0; j<front.size(); j++){
            letters_a[front[j]-'a']++;
        }
        for(int j=0; j<back.size(); j++){
            letters_b[back[j]-'a']++;
        }
        for(int j=0; j<26; j++){
            letters[j]+=max(letters_a[j], letters_b[j]);
        }
    }

    for(auto x:letters){
        out << x << "\n";
    }

    return 0;
}