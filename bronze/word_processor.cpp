#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ifstream in("word.in");
    ofstream out("word.out");
    string word;
    int n, k, current_len=0;
    in >> n >> k;

    rep(i, n){
        in >> word;
        if(word.length()>k-current_len){
            out << "\n" << word;
            current_len=word.length();
        }
        else{
            if(current_len!=0){
                out << " ";
            }
            out << word;
            current_len+=word.length();
        }
    }


    return 0;
}